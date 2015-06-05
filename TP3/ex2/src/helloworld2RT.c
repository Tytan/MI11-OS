#include <sys/mman.h>
#include <native/task.h>
#include <native/sem.h>
#include <rtdk.h>

#include <unistd.h>

#define TASK_PRIO  99 
#define TASK_MODE  0  /* No flags */
#define TASK_STKSZ 0  /* Stack size (use default one) */

RT_SEM sem[2];
RT_TASK task1, task2;

void task1_body (void *cookie) {
	int i, err;
	RT_SEM *sem;
	sem = (RT_SEM*) cookie;
	for (i=0;i<10;i++) {
		err = rt_sem_p(&sem[0], TM_INFINITE);
		if (err) {
			rt_printf("Failed to acquire sem 0 : %i\n", err);
		}
		rt_printf("Hello ");
		rt_task_sleep(100000);
		err = rt_sem_v(&sem[1]);
		if (err) {
			rt_printf("Failed to release sem 1 : %i\n", err);
		}
	}
}

void task2_body (void *cookie) {
	int i, err;
	RT_SEM *sem;
	sem = (RT_SEM*) cookie;
	for (i=0;i<10;i++) {
		err = rt_sem_p(&sem[1], TM_INFINITE);
		if (err) {
			rt_printf("Failed to acquire sem 1 : %i\n", err);
		}
		rt_printf("World RT !\n");
		rt_task_sleep(100000);
		err = rt_sem_v(&sem[0]);
		if (err) {
			rt_printf("Failed to release sem 0 : %i\n", err);
		}
	}
}

void cleanup (void) {
	rt_task_delete(&task1);
	rt_task_delete(&task2);
}

int main () {
	int err, err1, err2;
	mlockall(MCL_CURRENT|MCL_FUTURE);
	rt_print_auto_init(1);
	err = rt_sem_create(&sem[0], "semHello", 1, S_FIFO);
	if (err) {
		rt_printf("Failed to create sem 0 : %i\n", err);
	}
	err = rt_sem_create(&sem[1], "semWorld", 0, S_FIFO);
	if (err) {
		rt_printf("Failed to create sem 1 : %i\n", err);
	}
	err1 = rt_task_create(&task1, "Hello", TASK_STKSZ, TASK_PRIO, TASK_MODE);
	err2 = rt_task_create(&task2, "WorldRT", TASK_STKSZ, TASK_PRIO, TASK_MODE);
	if (!err1)
		rt_task_start(&task1,&task1_body,sem);
	if (!err2)
		rt_task_start(&task2,&task2_body,sem);
	sleep(5);
	return 0;
}

