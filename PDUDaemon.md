#tests #automatization #pdudaemon

# Ссылки:

1. Репозиторий: https://github.com/pdudaemon/pdudaemon

# Проблемы, которые должен решить PDUDaemon

* Обработка нескольких одновременных запросов

# Заметки

PDU - Power Distribution Units

## Обработка нескольких команд

```conf
    "pdus": {
        "test1": {
            "driver": "cdktest"
        },
        "test2": {
            "driver": "cdktest"
        }
    }
```

В случае, если отправляются две команды на одно и то же устройство (pdu), то очередность
выполняется:

```
curl -q "http://localhost:16421/power/control/on?hostname=test1&port=1"
# запускалось с другого ПК
curl -q "http://dojo-pc.elvees.com:16421/power/control/on?hostname=test1&port=2"
```

В случае, если отправляются две команды на разные устройства с одним и тем же драйвером,
то возникает исключение:

```
curl -q "http://localhost:16421/power/control/on?hostname=test1&port=1"
# запускалось с другого ПК
curl -q "http://dojo-pc.elvees.com:16421/power/control/on?hostname=test2&port=2"

...
Exception: Relay is busy
```

```pdudaemon/drivers/cdktest.py
    def _port_interaction(self, command, port_number):
        if CdkTest.is_busy:
            raise Exception("Relay is busy")

        CdkTest.is_busy = True
        log.debug("FOOBAR: cmd: %s; port: %s; busy: %s" % (command, port_number, CdkTest.is_busy))
        time.sleep(10)
        CdkTest.is_busy = False
```

## Незадокументированные фичи

* Возможность указать количество попыток при отправке команды:

```
    "pdus": {
        "test": {
            "driver": "localcmdline",
            "retries": 3,
        }
    }
```
