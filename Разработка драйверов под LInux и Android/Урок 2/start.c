#include <linux/module.h>

MODULE_LICENSE("GPL") ;
MODULE _AUTHOR("IVS <mymail@ru>");

int init_module(void) {
    printk(KERN ALERT "Hello from kernel module!");
    return 0;
}
