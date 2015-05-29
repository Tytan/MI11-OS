#include <sys/mman.h>
#include <native/task.h>

#include <unistd.h>

#define TASK_PRIO  99 /* Highest RT priority */
#define TASK_MODE  0  /* No flags */
#define TASK_STKSZ 0  /* Stack size (use default one) */

RT_TASK task1, task2;
void task1_body (void *cookie) {
	for (;;) {
		printf("Hello ");
		rt_task_sleep(100000000);
	}
}

void task2_body (void *cookie) {
	for (;;) {
		printf("World RT !\n");
		rt_task_sleep(100000000);
	}
}

void cleanup (void) {
	rt_task_delete(&task1);
	rt_task_delete(&task2);
}

int main () {
	int err1, err2;
	mlockall(MCL_CURRENT|MCL_FUTURE);
	err1 = rt_task_create(&task1, "Hello", TASK_STKSZ, TASK_PRIO, TASK_MODE);
	err2 = rt_task_create(&task2, "WorldRT", TASK_STKSZ, TASK_PRIO, TASK_MODE);
	if (!err1)
		rt_task_start(&task1,&task1_body,NULL);
	if (!err2)
		rt_task_start(&task2,&task2_body,NULL);
	sleep(3);
	cleanup();
	printf("Cleaned up task\n");
	sleep(3);
	printf("Exit\n");
	return 0;
}

