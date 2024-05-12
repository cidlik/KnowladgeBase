#net #dns

# Ссылки

1. https://cdnnow.ru/blog/dnslocal/
2. https://cloud.yandex.ru/docs/dns/tutorials/local-dns-cache
3. https://www.opennet.ru/docs/RUS/tcp_conf/tcp07.html


## Конфигурации

### CentOS 8

```
NetworkManager:
    DHCP client: internal
    resolver: dnsmasq
```
