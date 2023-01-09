# Python. tox

#python #tox #tests

### Ссылки

1. Документация: https://tox.wiki/en/latest/index.html

### Конфигурирование

"Из коробки" tox поддерживает форматы конфигурации:
- tox.ini;
- pyproject.toml;
- setup.cfg.

*Note* Пока что буду изучать только tox.ini.

Пример tox.ini:
   ```
   [tox]
   min_version = 4.0  ; минимальная версия tox
   env_list =  ; список используемых окружений
      py310    ; Python 3.10
      py39     ; Python 3.9
      type     ; см. ниже [testenv:type]

   [testenv]
   deps = pytest  ; пакетные зависимости, в данном случае, требуется установить pytest
   commands = pytest tests ;  комманда для данной среды

   [testenv:type]
   deps = mypy  ; про mypy см. ниже
   commands = mypy src
   ```

В секции `[tox]` указываются настройки непосредственно tox.
В секции `[testenv: "something"]` указываются настройки окружения. Если `"something"` не
будет найдена, то будут запущены настройки из `[testenv]` - по умолчанию.


##### Некоторые опции core ([tox])

`requires` - зависимости, которые нужно установить в среду, чтобы tox мог запускать коммандочки.

TBU

##### Некоторые опции окружений ([testenv])

TBU

### Заметки

TBU

### Популярные штуки, которые запускают при помощи tox

##### mypy

TBU

##### pre-commit

- Если выпонить `pre-commit autoupdate`, то можно будет обновить .pre-commit-config.yaml,
  а точнее версии пакетов в нем.

##### pytest

TBU