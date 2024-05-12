/*
 * Директория linux (include/linux) хранит заголовочные файлы
 * для системной разработки.
 */
#include <linux/module.h>

#ifndef DRV_PREFIX
#define DRV_PREFIX "[testdriver]: "
#endif

static int testparam = 0;
/*
 * Заметки:
 * 	 * Третий аргумент - разрешение доступа:
 * 	     * S_IRUGO - все могут только читать;
 *       * S_IWUSR - писать может только root;
 *     	 * ост. https://elixir.bootlin.com/linux/latest/source/include/linux/stat.h#L11
 *   * Найти параметры можно в /sys/module/testdriver/parameters
 */
module_param(testparam, int, S_IRUGO | S_IWUSR);

/*
 * Заметки:
 *   1. static стоят, чтобы область действия функций ограничивалась только
 *      этом файле.
 *   2. Значение __init и __exit в include/linux/init.h
 * 	 3. Ставить void в скобках *_init и *_exit обязательно. Где-то должно быть
 *      прописано.
 *      FYI. Если в аргументе функции пусто, то в нее можно передать любое
 *      количество аргументов. Если void - то вообще ничего нельзя передавать.
 * 	 4. KERN_ALERT etc -> include/linux/kern_levels.h
 */
static int __init testdriver_init(void)
{
	printk(KERN_ALERT DRV_PREFIX "module was inited\n");
	printk(KERN_ALERT DRV_PREFIX "testparam: %d\n", testparam);
	return 0;
}

static void __exit testdriver_exit(void)
{
	printk(KERN_ALERT DRV_PREFIX "module exited!\n");
}

/*
 * См linux/module.h
 */
module_init(testdriver_init);
module_exit(testdriver_exit);

MODULE_AUTHOR("cidlik <zubastikiko@gmail.com>");
MODULE_LICENSE("GPL");
