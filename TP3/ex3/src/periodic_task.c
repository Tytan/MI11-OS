#include <sys/mman.h>
#include <native/task.h>
#include <native/timer.h>
#include <rtdk.h>

#include <unistd.h>

#define TASK_PRIO  99 /* Highest RT priority */
#define TASK_MODE  0  /* No flags */
#define TASK_STKSZ 0  /* Stack size (use default one) */

#define T_TICK 10000000

RT_TASK task_desc;

void task_body (void *cookie) {
	int i;
	RTIME now, previous;
	rt_task_set_periodic(NULL, TM_NOW, T_TICK);
	while (1) {
		rt_task_wait_period(NULL);

		now = rt_timer_read();
		rt_printf("%.4f\n", (double)(now - previous)/1000000.0);
		previous = now;
	}
}

int main () {
	int err;
	mlockall(MCL_CURRENT|MCL_FUTURE);
	rt_print_auto_init(1);
	err = rt_task_create(&task_desc, "HelloWorldRT", TASK_STKSZ, TASK_PRIO, TASK_MODE);
	if (!err) {
		rt_task_start(&task_desc,&task_body,NULL);
	}
	while (1)
		sleep(1);
	return 0;
}
