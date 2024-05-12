#uboot #debug

### Ресурсы

1. Документация: https://u-boot.readthedocs.io/en/latest/develop/driver-model/debugging.html

### Заметки

* Если можно отладиться в sandbox, то отладиться в sandbox.
* Добавить в начало файла `#define DEBUG`. Это разрешит все `debug()` и `log_debug()` в этом файле.
	* Когда используется логирование, следует задать `CONFIG_LOG_DEFAULT_LEVEL=7`
* Использование `CONFIG_LOG_ERROR_RETURN` позволит вывести все функции, где были найдены ошибки.
* Использование `CONFIG_DEBUG_UART` позволит раньше включить UART для отладки (проверить).
* Коды ошибок можно посмотреть в `<U-BOOT_REPO>/include/linux/errno.h`.
	* `-ENOMEM` - не хватило памяти;
	* `-EINVAL` - обычно показывает, что что-то не так с деревом устройств.
* Для проверки связывания можно использовать `dm_dump_all()` - [дамп всех устройств (?)](https://github.com/ARM-software/u-boot/blob/master/drivers/core/dump.c#L46)
* В случае, если вообще ничего не понятно, попробовать добавить `#define LOG_DEBUG` в `drivers/core/lists.c` (проверить).
