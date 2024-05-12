#linux #shell #command

**Note** Располагать в алфавитном порядке!

# Полезные команды linux

* `nm` - перечисление символов в объектных файлах. Входит в состав Binutils.
  Пример вызова для testdriver.ko (см. "Разработка драйверов под Linux и
  Android", урок 1).

  ```
  user@userMint:~/wd/lesson2$ nm ../lesson1/build/testdriver.ko
  0000000000000000 T cleanup_module
                  U __fentry__
  0000000000000000 T init_module
  0000000000000078 r __module_depends
                  U param_ops_int
  0000000000000000 r __param_str_testparam
  0000000000000000 r __param_testparam
                  U printk
  0000000000000000 t testdriver_exit
  0000000000000000 t testdriver_init
  0000000000000000 b testparam
  0000000000000000 D __this_module
  000000000000000c r __UNIQUE_ID_author15
  0000000000000000 r __UNIQUE_ID_license16
  000000000000008d r __UNIQUE_ID_name15
  0000000000000081 r __UNIQUE_ID_retpoline16
  0000000000000050 r __UNIQUE_ID_srcversion17
  0000000000000032 r __UNIQUE_ID_testparamtype14
  000000000000009d r __UNIQUE_ID_vermagic14
  ```

* `strings` - вывод печатаемых строк из объектных файлов. Крайне полезна, т.к.
  `grep` может не показать требуемое вхождение. Входит в состав Binutils.
  Пример использования - определение версии ядра, для которой собран модуль:

  ```
  user@userMint:~/wd/lesson2$ strings ../lesson1/build/testdriver.ko | grep -i vermagic
  vermagic=4.15.0-20-generic SMP mod_unload
  __UNIQUE_ID_vermagic14
  ```
