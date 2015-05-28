/* NOYAU.C */
/*--------------------------------------------------------------------------*
 *               Code C du noyau preemptif qui tourne sur ARM                *
 *                                 NOYAU.C                                  *
 *--------------------------------------------------------------------------*/

#include <stdint.h>

#include "interrupt.h"
#include "serialio.h"
#include "timer.h"
#include "noyau.h"


/*--------------------------------------------------------------------------*
 *            Variables internes du noyau                                   *
 *--------------------------------------------------------------------------*/
static int compteurs[MAX_TACHES]; /* Compteurs d'activations */
CONTEXTE _contexte[MAX_TACHES];   /* tableau des contextes */
volatile uint16_t _tache_c;       /* numéro de tache courante */
uint32_t  _tos;                   /* adresse du sommet de pile */
int _ack_timer = 1;              /* = 1 si il faut acquitter le timer */
#define IRQ_FREQ 100

/*--------------------------------------------------------------------------*
 *                        Fin de l'execution                                *
 *----------------------------------------------------------------------- --*/
void noyau_exit(void) {
 	/* Désactiver les interruptions */
	printf("Sortie du noyau\n");
	/* afficher par exemple le nombre d'activation de chaque tache */
								
	/* Terminer l'exécution */
	
}

/*--------------------------------------------------------------------------*
 *                        --- Fin d'une tache ---                           *
 * Entree : Neant                                                           *
 * Sortie : Neant                                                           *
 * Descrip: Cette proc. doit etre appelee a la fin des taches               *
 *                                                                          *
 *----------------------------------------------------------------------- --*/
void fin_tache(void) {
	/* on interdit les interruptions */
	_irq_disable_();
	/* la tache est enlevee de la file des taches */
	retire(_tache_c);
	schedule();
}

/*--------------------------------------------------------------------------*
 *                        --- Creer une tache ---                           *
 * Entree : Adresse de la tache                                             *
 * Sortie : Numero de la tache creee                                        *
 * Descrip: Cette procedure cree une tache en lui allouant                  *
 *    - une pile (deux piles en fait une pour chaque mode du processeur)    *
 *    - un numero                                                           *
 * Err. fatale: priorite erronnee, depassement du nb. maximal de taches     *
 *	                                                                        *
 *--------------------------------------------------------------------------*/
uint16_t cree(TACHE_ADR adr_tache) {
	/*
	compteurs[j] = 0;
	_contexte[j].sp_irq = _tos;
	_tos -= PILE_IRQ;
	_contexte[j].sp_ini = _tos;
	_tos -= PILE_TACHE;
	*/
	CONTEXTE *p;                  /* pointeur d'une case de _contexte */
	static uint16_t tache = -1;   /* contient numero dernier cree */


	/* debut section critique */
	/* numero de tache suivant */
	tache++;

	/* sortie si depassement */
	if (tache >= MAX_TACHES) {
		/* sortie car depassement       */
		return MAX_TACHES;
	}
	
	/* initialisation du compteur d'activations */
	compteurs[tache] = 0;
	/* contexte de la nouvelle tache */
	p = &(_contexte[tache]);

	/* allocation d'une pile a la tache & decrementation du pointeur de pile pour la prochaine tache. */
	p->sp_irq = _tos;
	_tos -= PILE_IRQ;
	p->sp_ini = _tos;
	_tos -= PILE_TACHE;

	/* fin section critique */

	/* memorisation adresse debut de tache */
	p->tache_adr = adr_tache;
	/* mise a l'etat CREE */
	p->status = CREE;

	return(tache);                  /* tache est un uint16_t */
}

/*--------------------------------------------------------------------------*
 *                          --- Elire une tache ---                         *
 * Entree : Numero de la tache                                              *
 * Sortie : Neant                                                           *
 * Descrip: Cette procedure place une tache dans la file d'attente des      *
 *	    taches eligibles.                                                   *
 *	    Les activations ne sont pas memorisee                               *
 * Err. fatale: Tache inconnue	                                            *
 *                                                                          *
 *--------------------------------------------------------------------------*/
void active(uint16_t tache) {
	CONTEXTE *p = &_contexte[tache]; /* acces au contexte tache */

	if (p->status == NCREE) {
		/* sortie du noyau */
		noyau_exit();
	}

	/* debut section critique */
	_lock_();
	/* n'active que si receptif */
	if (p->status == CREE) {
		/* changement d'etat, mise a l'etat PRET */
		p->status = PRET;
		/* ajouter la tache dans la liste */
		ajoute(tache);
		/* activation d'une tache prete */
	}
	/* fin section critique */
	_unlock_();
}


/*--------------------------------------------------------------------------*
 *                  ORDONNANCEUR preemptif optimise                         *
 *                                                                          *
 *             !! Cette fonction doit s'exécuter en mode IRQ !!             *
 *  !! Pas d'appel direct ! Utiliser schedule pour provoquer une            *
 *  commutation !!                                                          *
 *--------------------------------------------------------------------------*/
void __attribute__((naked)) scheduler(void) {
	register CONTEXTE *p;
	register unsigned int sp asm("sp");  /* Pointeur de pile */

	/* Sauvegarder le contexte complet sur la pile IRQ */
	__asm__ __volatile__(
		/* Sauvegarde registres mode system */
		"stmfd sp,{r0-r12,sp,lr}^\t\n"
		/* Attendre un cycle */
		"nop\t\n"
		/* Ajustement pointeur de pile */
		"sub sp, sp, #60"
		/* Sauvegarde lr IRQ */
		"stmfd sp!,{lr}\t\n"
		/* Sauvegarde de spsr_irq */
		"mrs r0, SPSR\t\n"
		"stmfd sp!,{r0}\t\n"
	);

	/* Réinitialiser le timer si nécessaire */
	if (_ack_timer) {
		/* Acquiter l'événement de comparaison du Timer pour pouvoir */
		/* obtenir le déclencement d'une prochaine interruption */
		timerComparedOccured(TIMER1);
	}
	else {
	  _ack_timer = 1;
	}

	/* memoriser le pointeur de pile */
	_contexte[_tache_c].sp_irq = sp;
	/* recherche du suivant */
	_tache_c = suivant();
	/* Incrémenter le compteur d'activations  */
	compteurs[_tache_c]++;
	/* p pointe sur la nouvelle tache courante*/
	p = &_contexte[_tache_c];

	/* tache prete ? */
	if (p->status == PRET) {
		/* Charger sp_irq initial */
		sp = p->sp_irq;
		/* Passer en mode système */
		_set_arm_mode_(ARMMODE_SYS);
		/* Charger sp_sys initial */
		sp = p->sp_ini;
		/* status tache -> execution */
		p->status = EXEC;
		/* autoriser les interuptions */
		_irq_enable_();
		/* lancement de la tâche */
		p->tache_adr();
	}
	else {
		/* tache deja en execution, restaurer sp_irq */
		sp = p->sp_irq;
	}

	/* Restaurer le contexte complet depuis la pile IRQ */
	__asm__ __volatile__(
		/* Restaurer spsr_irq */
		"ldrfd sp!,{r0}\t\n"
		"msr SPSR, r0\t\n"
		/* et lr_irq */
		"ldrfd sp!,{lr}\t\n"
		/* Restaurer registres mode system */
		"ldrfd sp,{r0-r12,sp,lr}^\t\n"
		/* Attendre un cycle */
		"nop\t\n"
		/* Ajuster pointeur de pile irq */
		"add sp, sp, #60\t\n"
		/* Retour d'exception */
		"subs pc, lr, #4\t\n"
	); 
}


/*--------------------------------------------------------------------------*
 *                  --- Provoquer une commutation ---                       *
 *--------------------------------------------------------------------------*/
void schedule(void) {
	/* Debut section critique */
	_lock_();
	_ack_timer = 0;
	/* On simule une exception irq pour forcer 
	 * un appel correct à scheduler().*/
	/* Passer en mode IRQ */
	_set_arm_mode_(ARMMODE_IRQ);
	__asm__ __volatile__(
		/* Sauvegarder cpsr dans spsr */
		"mrs r0, CPSR\t\n"
		"msr SPSR, r0\t\n"
		/* Sauvegarder pc dans lr et l'ajuster */
		"adds lr, pc, #4" // TODO voir s'il ne faut pas mettre 8
		/* Saut à scheduler */
		"b scheduler"
		:::"r0");
	/* Repasser en mode system */
	_set_arm_mode_(ARMMODE_SYS);
	/* Fin section critique */
	_unlock_();
}

/*--------------------------------------------------------------------------*
 *                        --- Lancer le systeme ---                         *
 * Entree : Adresse de la premiere tache a lancer                           *
 * Sortie : Neant                                                           *
 * Descrip: Active la tache et lance le systeme                             *
 *                                                                          *
 *                                                                          *
 * Err. fatale: Neant                                                       *
 *                                                                          *
 *--------------------------------------------------------------------------*/
void start(TACHE_ADR adr_tache) {
	short j;
	register unsigned int sp asm("sp");

	for (j=0; j<MAX_TACHES; j++) {
		/* initialisation de l'etat des taches */
		_contexte[j].status = NCREE;
	}
	/* Initialisation de la variable Haut de la pile des tâches */
	_tos = sp;

	/* initialisation de la file */
	file_init();

	/* initialisation de la tache courante */
	_tache_c = cree(adr_tache);

	/* ajout de la tache a la file */
	ajoute(_tache_c);


	/* Passer en mode IRQ */
	_set_arm_mode_(ARMMODE_IRQ);
	/* sp_irq initial */
	sp = _contexte[_tache_c].sp_irq;
	/* Repasser en mode SYS */
	_set_arm_mode_(ARMMODE_SYS);

	/* on interdit les interruptions */
	_irq_disable_();

	/* Initialisation du timer à 100 Hz */
	timerInit(TIMER1, IRQ_FREQ);

	/* Initialisation de l'AITC */
	timerEnableInterrupt(TIMER1);

	/* creation et activation premiere tache */
	active(_tache_c);
}


/*-------------------------------------------------------------------------*
 *                    --- Endormir la tâche courante ---                   *
 * Entree : Neant                                                          *
 * Sortie : Neant                                                          *
 * Descrip: Endort la tâche courante et attribue le processeur à la tâche  *
 *          suivante.                                                      *
 *                                                                         *
 * Err. fatale:Neant                                                       *
 *                                                                         *
 *-------------------------------------------------------------------------*/

void dort(void) {

}

/*-------------------------------------------------------------------------*
 *                    --- Réveille une tâche ---                           *
 * Entree : numéro de la tâche à réveiller                                 *
 * Sortie : Neant                                                          *
 * Descrip: Réveille une tâche. Les signaux de réveil ne sont pas mémorisés*
 *                                                                         *
 * Err. fatale:tâche non créée                                             *
 *                                                                         *
 *-------------------------------------------------------------------------*/


void reveille(uint16_t t) {

}
