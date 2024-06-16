#include <stdio.h>
#include <unistd.h>

#define MAX_COUNT 100

int main() {
    printf("Count to %d\n", MAX_COUNT);
    int i;
    for (i = 0; i < MAX_COUNT; i++) {
        printf("Count: %d\n", i);
        sleep(1);
    }
    return 0;
}
