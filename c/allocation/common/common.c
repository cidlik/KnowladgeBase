#include <stdio.h>

#include "common.h"

void print_int_arr(int *p, int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
}

void separator(void) {
    printf("==================\n");
}
