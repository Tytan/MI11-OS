#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <sys/mman.h>
#include <stdint.h>

#include <native/task.h>
#include <native/timer.h>
#include <native/mutex.h>

#include <rtdk.h>

#define TASK_PRIO_HIGH  99 /* Highest RT priority */
#define TASK_PRIO_MID  89 /* Highest RT priority */
#define TASK_PRIO_LOW  79 /* Highest RT priority */
#define TASK_MODE  0  /* No flags */
#define TASK_STKSZ 0  /* Stack size (use default one) */

RT_TASK task_high_prio;
RT_TASK task_mid_prio;
RT_TASK task_low_prio;

RT_MUTEX mutex_SC;

int shared_resource = 0;

///////////////////////////////////////////////////////////
void task_A (void *arg __attribute__((__unused__)))
{
  rt_printf("task_A started\n");

  /* wait for 2 second ( 2e9 nanosec ) */ 
  rt_task_sleep(2e9);

  /* take the resource */ 
  rt_mutex_acquire(&mutex_SC, TM_INFINITE);

  shared_resource = shared_resource + 1;
  rt_printf("task_A - shared_resource = %d\n", shared_resource);
  
  rt_printf("task_A finished\n");
  
  /* release the resource */ 
  rt_mutex_release(&mutex_SC);
}

///////////////////////////////////////////////////////////
void task_B (void *arg __attribute__((__unused__)))
{
  rt_printf("task_B started\n");

  /* wait for 3 second ( 3e9 nanosec ) */ 
  rt_task_sleep(3e9);

  rt_printf("task_B - shared_resource = %d\n", shared_resource);

  rt_printf("task_B finished\n");
}

///////////////////////////////////////////////////////////
void task_C (void *arg __attribute__((__unused__)))
{
  rt_printf("task_C started\n");

  /* wait for 1 second ( 1e9 nanosec ) */ 
  rt_task_sleep(1e9);

  rt_mutex_acquire(&mutex_SC, TM_INFINITE);

  /* Busy wait during 10 seconds before releasing the resource */ 
  RTIME t = rt_timer_read(); 
  while ( rt_timer_ticks2ns(rt_timer_read() - t ) < 10e9 ) {}

  shared_resource = shared_resource + 1;
  rt_printf("task_C - shared_resource = %d\n", shared_resource);

  rt_printf("task_C finished\n");

  rt_mutex_release(&mutex_SC);
}

void catch_signal() {}
 
int main(void)
{  
	int err;
    //signal(SIGTERM, catch_signal);
    //signal(SIGINT, catch_signal);

    /* Avoids memory swapping for this program */
    mlockall(MCL_CURRENT|MCL_FUTURE);
    rt_print_auto_init(1);
	rt_mutex_create(&mutex_SC, "coucoucmoi");

	err = rt_task_create(&task_high_prio, "task1", TASK_STKSZ, TASK_PRIO_HIGH, TASK_MODE);
	if (!err) {
		rt_task_start(&task_high_prio,&task_A,NULL);
	}

	err = rt_task_create(&task_mid_prio, "task2", TASK_STKSZ, TASK_PRIO_MID, TASK_MODE);
	if (!err) {
		rt_task_start(&task_mid_prio,&task_B,NULL);
	}

	err = rt_task_create(&task_low_prio, "task3", TASK_STKSZ, TASK_PRIO_LOW, TASK_MODE);
	if (!err) {
		rt_task_start(&task_low_prio,&task_C,NULL);
	}
	while (1)
		sleep(1);
    
    return 0;
}
