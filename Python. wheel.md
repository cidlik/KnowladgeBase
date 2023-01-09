# Python. wheel

#python #pip #wheel

### Ссылки

1. Статья на русском: https://dizballanze.com/ru/python-wheels-dlia-bystroi-ustanovki-zavisimostei/

### Почему простая установка через pip - плохо

1. Проиводительность страдает - требуется скачать пакет и собрать его.
2. Нет возможности установить пакеты в оффлайн режиме.
3. Нестабильно - неполадки на стороне PyPl, VCS (version control system e.g. GitHub),
   наружение зависимостей etc.

### Wheel

**Wheel** - это "архив" пакетов.

Различается сбор пакетов из VCS и из PyPl

Для сбора из PyPl сделать:

    ```
    pip wheel -w <dist-dir> -r <requirements-file> --pre --allow-all-external
    ```

Для сбора внешних пакетов:

    ```
    cd <src/external-package>
    python setup.py bdist_wheel --dist-dir <dist-dir>
    ```

