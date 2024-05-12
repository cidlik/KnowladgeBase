#include <stdio.h>


void simple_demonstration() {
    printf("%s()\n", __func__);
    int var = 123;
    int *pVar = &var;

    printf("var = %d; pVar = %p; *pVar = %d\n", var, pVar, *pVar);
}

void operations() {
    printf("%s()\n", __func__);
    int x = 1, y = 2, *pInt;
    printf("x = %d; y = %d; pInt = %p\n", x, y, pInt);
    pInt = &x;
    printf("x = %d; y = %d; pInt = %p\n", x, y, pInt);
    *pInt = 3;
    printf("x = %d; y = %d; pInt = %p\n", x, y, pInt);
    y = *pInt;
    printf("x = %d; y = %d; pInt = %p\n", x, y, pInt);
}


void wrong_swap(int a, int b) {
    printf("--- Wrong swap ---\n");
    printf("a = %d; *a = %p; b = %d; *b = %p;\n", a, &a, b, &b);
    int tmp = a;
    a = b;
    b = tmp;
    printf("a = %d; *a = %p; b = %d; *b = %p;\n", a, &a, b, &b);
    printf("------- end ------\n");
}


void correct_swap(int *a, int *b) {
    printf("--- Correct swap ---\n");
    printf("a = %d; *a = %p; b = %d; *b = %p;\n", *a, a, *b, b);
    int tmp = *a;
    *a = *b;
    *b = tmp;
    printf("a = %d; *a = %p; b = %d; *b = %p;\n", *a, a, *b, b);
    printf("-------- end -------\n");
}


void arrays() {
    printf("%s()\n", __func__);
#define LEN 10
    int i;
    int a[LEN];
    for (i = 0; i < LEN; i++) {
        a[i] = 2 * i;
        printf("%d ", a[i]);
    }
    printf("\n");

    int *pa;
    pa = &a[0];
    printf("pa = %p; *pa = %d; *pa + 2 = %d; *(pa + 2) = %d\n", pa, *pa, *pa + 2, *(pa + 2));
    pa = a;
    for (i = 0; i < LEN; i++) {
        printf("%d ", pa[i]);
    }
    printf("\n");
    printf("a[4] = %d; *(a + 4) = %d\n", a[4], *(a + 4));
}


int cdk_strlen(char *s) {
    int n;
    for (n = 0; *s != '\0'; s++) {
        printf("*s = %d\n", *s);
        n++;
    }
    return n;
}


void check_strlen() {
    printf("%s()\n", __func__);
    char *s = "Hello!";
    printf("'%s' len = %d\n", s, cdk_strlen(s));
}


void swap_demonstration() {
    printf("%s()\n", __func__);
    int a = 3, b = 4;
    wrong_swap(a, b);
    printf("a = %d, b = %d\n", a, b);
    correct_swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);
}


void _copy_str(char *s, char *d) {
    // for (; (*d = *s) != '\0'; s++) {
    //     d++;
    // }

    // for (; (*d++ = *s++) != '\0';);

    // for (; (*d++ = *s++););

    while((*d++ = *s++));
}

void copy_str() {
    printf("%s()\n", __func__);
    char *s = "Test";
    char *d1, *d2;
    int p;
    printf("Values:     s = %s; d1 = %s; d2 = %s\n", s, d1, d2);
    printf("Pointers:   s = %p; d1 = %p; d2 = %p\n", s, d1, d2);
    d1 = s;
    printf("Values:     s = %s; d1 = %s; d2 = %s\n", s, d1, d2);
    printf("Pointers:   s = %p; d1 = %p; d2 = %p\n", s, d1, d2);
    _copy_str(s, d2);
    printf("Values:     s = %s; d1 = %s; d2 = %s\n", s, d1, d2);
    printf("Pointers:   s = %p; d1 = %p; d2 = %p\n", s, d1, d2);
}


/**
 * Copy t string to the end of s
*/
char * _strcat(char *dest, char *src) {
    while (*dest != '\0') {
        dest++;
    }
    while ((*dest++ = *src++));
    return dest;
}


void test_strcat() {
    printf("%s()\n", __func__);
    char dest[1024] = "Foo";
    char *src = "Hello";
    char *p;
    _strcat(dest, "Hello");
    _strcat(dest, "Shit");
    p = _strcat(dest, "World");
    printf("Result: %s\n", dest);

    printf("dest = %p; p = %p\n", dest, p);
}


void void_pointers() {
    printf("%s()\n", __func__);
    void *p;
    int i = 10;
    p = &i;
    printf("&i = %p; p = %p; i = %d; *((int *)p) = %d\n", &i, p, i, *((int *)p));
    char *s = "some string";
    p = s;
    printf("s = %s; (char *)p = %s\n", s, (char *)p);
}


int main() {
    printf("=======================\n");
    simple_demonstration();
    printf("=======================\n");
    operations();
    printf("=======================\n");
    swap_demonstration();
    printf("=======================\n");
    arrays();
    printf("=======================\n");
    check_strlen();
    printf("=======================\n");
    copy_str();
    printf("=======================\n");
    test_strcat();
    printf("=======================\n");
    void_pointers();
    return 0;
}
