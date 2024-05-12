#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("IVS <mymail@ru>");

void cleanup_module(void) {
    printk(KERN ALERT "Module 'hello' has exited!");
    return;
}
