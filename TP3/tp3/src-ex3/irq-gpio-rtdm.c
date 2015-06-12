#include <linux/fs.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>
#include <linux/module.h>
#include <linux/irq.h>

#include <rtdm/rtdm_driver.h>

// GPIO IN IT 
#define MI11_GPIO_IN  ( GPIO_PORTA | GPIO_PF | 2 )
// GPIO OUT LED 
#define MI11_GPIO_OUT 127
#define DELAY (10)

static rtdm_irq_t irq_rtdm;
static int counter = 0;
extern unsigned long volatile jiffies;


// Management of the interruption
static int mi11_handler_interruption(rtdm_irq_t * irq)
{
	static int value = 0;
	static uint64_t last_time, time;

	time = jiffies;
	if (time - last_time < DELAY) {
		return RTDM_IRQ_HANDLED;
	}
	counter++; 
	value = !value;
	
	// use the function to change the state of the GPIO, you can alternate the value of 'value'
	gpio_direction_output(MI11_GPIO_OUT, value);

	//not advised, just to have a trace of the execution during debug
	printk("led,c=%d\n", counter);
	last_time = time;
	return RTDM_IRQ_HANDLED;
}


// Installation of IRQ
static int __init mi11_init (void)
{
	int err, irq;

	err = gpio_request(MI11_GPIO_IN, "mi11in");
	if (err)
		goto free_in;
	err = gpio_request(MI11_GPIO_OUT, "mi11out");
	if (err) 
		goto free_out;

	err = gpio_direction_output(MI11_GPIO_OUT, 0);
	if (err) 
		goto free_out;
	err = gpio_direction_input(MI11_GPIO_IN);
	if (err) 
		goto free_out;

	irq = gpio_to_irq(MI11_GPIO_IN);
	err = set_irq_type(irq, IRQ_TYPE_EDGE_BOTH);
	if (err) 
		goto free_out;

	err = rtdm_irq_request(&irq_rtdm, irq, mi11_handler_interruption, RTDM_IRQTYPE_EDGE, "myirq", NULL);
	if (err) 
		goto free_out;

	err = rtdm_irq_enable(&irq_rtdm);
	if (err) 
		goto free_out;

	return 0; 
free_out:
	gpio_free(MI11_GPIO_OUT);
free_in:
	gpio_free(MI11_GPIO_IN);
	return err;
}


// Cleanup
static void __exit mi11_exit (void)
{
	rtdm_irq_disable(&irq_rtdm);
	rtdm_irq_free(&irq_rtdm);
	gpio_free(MI11_GPIO_OUT);
	gpio_free(MI11_GPIO_IN);
}


module_init(mi11_init);
module_exit(mi11_exit);
MODULE_LICENSE("GPL");

