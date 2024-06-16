#tests #automatization #labgrid

# Ссылки

1. Документация: https://labgrid.readthedocs.io/en/latest/

# Заметки

## Запуск сервиса вручную

Все запускать из корня репозитория

### Координатор

`/opt/labgrid/.crossbar/config.yam` пробрасывается при сборке образа.

```
docker run \
    -v ./dockerfiles/staging/crossbar:/home/root/crossbar \
    --tty \
    --rm \
    --network host \
    --name labgrid-coordinator \
    labgrid-coordinator \
    bash -c "cp /home/root/crossbar/places_example.yaml /opt/crossbar/places.yaml &&
      crossbar start --config /opt/labgrid/.crossbar/config.yaml"
```

### Экспортер

Запускать после координатора

```
docker run \
    -v ./dockerfiles/staging/exporter-conf:/opt/conf \
    -v /run/udev:/run/udev:ro \
    --tty \
    --rm \
    --interactive \
    --network host \
    --name labgrid-exporter \
    labgrid-exporter \
    bash -c "set -e &&
        /opt/wait-for-it/wait-for-it.sh 127.0.0.1:20408 -- labgrid-exporter /opt/conf/exporter.yaml"
```

### Клиент

Запускать после координатора и экспортера

```
docker run \
    -v ./dockerfiles/staging/client/simple-test:/remote-test \
    -v /home/$(whoami)/.ssh:/home/$(whoami)/.ssh \
    --tty \
    --interactive \
    --network host \
    --tmpfs /tmp \
    --detach \
    --rm \
    --name labgrid-client \
    labgrid-client
```

Базовые команды

```
root@dojo-pc:/# labgrid-client places
example-place
root@dojo-pc:/# labgrid-client resources
dojo-pc.elvees-nix.com/example-group/NetworkService

# docker exec -it labgrid-client labgrid-client places
# docker exec -it labgrid-client labgrid-client resources
```

Запрос с другого ПК
```
labgrid-client -x  ws://dojo-pc.elvees-nix.com:20408/ws places
```
