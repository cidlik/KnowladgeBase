#include <stdio.h>

#include <custom-lib.h>

int main()
{
    printf("This is test program\n");
    printf("custom-lib: sum_int: retval = %d\n", sum_int(3, 4));
    return 0;
}
