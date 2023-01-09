# Linux. udev

#linux #udev #udevadm

### Ссылки

1. Перевод мануала udevadm: https://manpages.ylsoftware.com/ru/udevadm.8.html
2. udev: https://wiki.archlinux.org/title/udev_(%D0%A0%D1%83%D1%81%D1%81%D0%BA%D0%B8%D0%B9)

### udev

TBU

### udevadm

**udevadm** - утилита для управления udev

```
    [rkuznecov@impact-pc ttydb]$ udevadm --help
    udevadm [--help] [--version] [--debug] COMMAND [COMMAND OPTIONS]

    Send control commands or test the device manager.

    Commands:
    info          Query sysfs or the udev database
    trigger       Request events from the kernel
    settle        Wait for pending udev events
    control       Control the udev daemon
    monitor       Listen to kernel and udev events
    test          Test an event run
    test-builtin  Test a built-in command
```

**udevadm info** - информация об устройстве.

*--quary* - вернуть указанный тип данных об устройстве.

*Example*:
```
    [rkuznecov@impact-pc ~]$ udevadm info --query=path --name=/dev/ttyUSB0
    /devices/pci0000:00/0000:00:14.0/usb3/3-1/3-1:1.0/ttyUSB0/tty/ttyUSB0
```
