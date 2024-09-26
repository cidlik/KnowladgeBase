#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "../common/common.h"

void copy_string_wrong(char *new) {
    printf("%s\n", __func__);

    char *original = "Test string";
    printf("Start: original %s\n", original);
    printf("Start: new:     %s\n", new);

    new = original;
    printf("Copy pointer: original: %s\n", original);
    printf("Copy pointer: new:      %s\n", new);
}

void copy_string_wrong_too(char *new) {
    printf("%s\n", __func__);
    printf("new pointer: %p\n", new);

    char *original = "Test string";
    printf("Start: original %s\n", original);
    printf("Start: new:     %s\n", new);

    new = (char *) malloc(strlen(original));
    memcpy(new, original, strlen(original));
    printf("Copy pointer: original: %s\n", original);
    printf("Copy pointer: new:      %s\n", new);
}

char * copy_string_right(char *new) {
    printf("%s\n", __func__);

    char *original = "Test string";
    printf("Start: original %s\n", original);
    printf("Start: new:     %s\n", new);

    new = (char *) malloc(strlen(original));
    memcpy(new, original, strlen(original));
    printf("Copy pointer: original: %s\n", original);
    printf("Copy pointer: new:      %s\n", new);
    return new;
}

int main() {
    char *new;
    separator();
    copy_string_wrong(new);
    printf("New string after wrong copy: %s\n", new);

    separator();
    printf("new pointer: %p\n", new);
    copy_string_wrong_too(new);
    printf("New string after right copy: %s\n", new);

    separator();
    new = copy_string_right(new);
    printf("New string after right copy: %s\n", new);
    return 0;
}
