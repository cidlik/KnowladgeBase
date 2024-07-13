/**
 * gcc -o runner runner.c
*/

#include <stdlib.h>

int main() {
    int status = system("./subrunner");
    return status;
}
