#include <sys/mman.h>
#include <native/task.h>

#include <unistd.h>

#define TASK_PRIO  99 /* Highest RT priority */
#define TASK_MODE  0  /* No flags */
#define TASK_STKSZ 0  /* Stack size (use default one) */

RT_TASK task_desc;
void task_body (void *cookie) {
	for (;;) {
		printf("Hello World RT !\n");
		rt_task_sleep(100000000);
	}
}

void cleanup (void) {
	rt_task_delete(&task_desc);
}

int main (int argc, char *argv[]) {
	int err;
	mlockall(MCL_CURRENT|MCL_FUTURE);
	err = rt_task_create(&task_desc, "HelloWorldRT", TASK_STKSZ, TASK_PRIO, TASK_MODE);
	if (!err)
		rt_task_start(&task_desc,&task_body,NULL);
	sleep(3);
	cleanup();
	printf("Cleaned up task\n");
	sleep(3);
	printf("Exit\n");
	return 0;
}
