# Введение

Проект https://github.com/martin-ger/esp32_nat_router/tree/master

# Подготовка

Установить `esptool`

```
virtualenv .venv --python=python3.12
# Linux
source .venv/bin/activate
# Windows
.venv\Scripts\activate
pip install esptool
```

# Прошивка

Проверить, что чип определяется. Для этого нажать и держать кнопку boot и выполнить
`esptool.exe chip_id`.

См. также https://github.com/martin-ger/esp32_nat_router/tree/master?tab=readme-ov-file#flashing-the-prebuild-binaries

Для esp-wroom-32 подходит прошивка из esp32/

Во время вызова удерживать boot кнопку
```
esptool.exe --chip esp32 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 40m --flash_size detect 0x1000 esp32_nat_router\build\esp32\bootloader.bin 0x8000 esp32_nat_router\build\esp32\partitions.bin 0x10000 esp32_nat_router\build\esp32\firmware.bin
```

# Настройка

* Подключиться к ESP32_NAT_Router
* Зайти http://192.168.4.1/
* В верхней части заполнить название новой сети, в нижнем - той, которую надо ретранслировать

После установки с сброса устройства у него сменится IP. Новый IP можно получить через
последовательный порт командой `show`.

Также там показывает пароли и SSID для исходной точки и для повторителя.
