#include <malloc.h>
#include <stdio.h>

#include "../common/common.h"


void test_malloc() {
    int i;
    int LEN = 4;
    printf("%s\n", __func__);

    int *pI = (int *) malloc(LEN * sizeof(int));
    print_int_arr(pI, LEN);
    print_int_arr(pI, LEN + 2);

    pI[0] = 3;
    pI[LEN - 1] = 5;
    pI[LEN + 1] = 7;
    print_int_arr(pI, LEN + 2);

    free(pI);
    print_int_arr(pI, LEN + 2);
}

void test_calloc() {
    int i;
    int LEN = 4;
    printf("%s\n", __func__);

    int *pI = (int *) calloc(LEN, sizeof(int));
    print_int_arr(pI, LEN);
    print_int_arr(pI, LEN + 2);

    pI[0] = 3;
    pI[LEN - 1] = 5;
    pI[LEN + 1] = 7;
    print_int_arr(pI, LEN + 2);

    free(pI);
    print_int_arr(pI, LEN + 2);
}


int main() {
    separator();
    test_malloc();
    separator();

    separator();
    test_calloc();
    separator();

    return 0;
}
