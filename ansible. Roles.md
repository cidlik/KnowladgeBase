#ansible #roles

# Ресурсы

1. Мануал: https://docs.ansible.com/ansible/latest/playbook_guide/playbooks_reuse_roles.html

# Заметки

Роли позволяют хранить скрипты, файлы, переменные и все в одном месте. Удобно
для переиспользования.

## Структура директории с ролью

Чтобы роль считалась ролью следует добавить хотя бы одну из следующих
директорий:

```
roles/
    foo/
        tasks/
        handlers/
        templates/
        files/
        vars/
        defaults/
        meta/
        library/
```

Дополнительные директории
```
        module_utils/
        lookup_plugins/
```

По умолчанию, Ansible просмотрит каждую директорию роли на предмет нахождения
внутри `main.yaml` (также `main.yml`).

* `tasks/main.yaml` - главный список задач (task), которые роль исполняет.
* `handlers/main.yaml` - обработчик, который может использоваться ролью или
  вне её.
* `library/my_module.py` - модули, которые могут использоваться ролью (см.
  [ Embedding modules and plugins in roles](https://docs.ansible.com/ansible/latest/playbook_guide/playbooks_reuse_roles.html#embedding-modules-and-plugins-in-roles)).
* `defaults/main.yaml` - значения переменных по умолчанию. Имеют наинизший
  приоритет.
* `vars/main.yaml` - еще переменные роли. Имеют довольно сильный приоритет.
  Видимо, используются, чтобы что-то извне не перезаписало какие-то значения
  (см. [тут](https://docs.ansible.com/ansible/latest/playbook_guide/playbooks_variables.html#understanding-variable-precedence)).
* `files/*` - файлы, которые развертывает роль.
* `templates/*` - шаблоны, которые развертывает роль
  ([пример](https://github.com/triplepoint/ansible-udev-rules/tree/main)).
* `meta/main.yaml` - метаданные роли, включающие зависимости роли и опциональные
  метаданные Galaxy, такие как поддерживаемые платформы.

Также не запрещается добавление дополнительных файлов в указанные директории.

## Поиск ролей

По умолчанию, проверяются пути:

* коллекции Ansible, если используется;
* в `roles/` относительно плейбука;
* в `ANSIBLE_ROLES_PATH`;
* в директории, где находится плейбук.

## Вызов роли

```
# some-role/tasks/main.yaml
- debug:
    msg: "{{ some_external_variable }}"
```

Способы:

1. на уровне плейбука при помощи `roles` (статический импорт);
2. на уровне задачи через `include_role` - динамическое переиспользование роли
  в `tasks` секции.
3. на уровне задачи через `import_role` - статическое переиспользование роли
  в `tasks` секции.

Пример для 1-го случая:
```
- hosts: localhost
  roles:
    - role: some-role
      vars:
        some_external_variable: foo

  tasks:
    - debug:
        msg: "{{ some_external_variable }}"
```
Отмечу, что `some_external_variable` будет доступна в `tasks` по умолчанию (
см. [ссылку](https://docs.ansible.com/ansible/latest/reference_appendices/config.html#default-private-role-vars)).

Пример для 2-го случая:
```
    - include_role:
        name: some-role
      vars:
        some_external_variable: foo

    - debug:
        msg: "{{ some_external_variable }}"

```
Т.к. импорт динамический, то переменная `some_external_variable` не будет видна
остальным таскам.

Пример для 3-го случая:
```
    - import_role:
        name: some-role
      vars:
        some_external_variable: foo

    - debug:
        msg: "{{ some_external_variable }}"

```

## Проверка аргументов роли

some-role/meta/argument_specs.yaml
```
argument_specs:
  main:
    options:
      some_external_variable:
        type: bool
        required: true
```

test.yaml
```
# ansible-playbook -i localhost, test.yaml

- hosts: localhost

  tasks:
    - import_role:
        name: some-role
      vars:
        some_external_variable: [42]

    - debug:
        msg: "{{ some_external_variable }}"
```
