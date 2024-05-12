/**
 * Helpful links:
 *   * https://firststeps.ru/linux/r.php?10
 *   * https://www.geeksforgeeks.org/getopt-function-in-c-to-parse-command-line-arguments/
*/


#include <stdio.h>
#include <unistd.h>


void help() {
    printf("Usage: test [-k <kwarg>] [-a]\n");
    printf("   -k kwarg     - some kwarg\n");
    printf("   -a           - some arg\n");
}

int main(int argc, char **argv) {
#if DEBUG
    int i;
    printf("argc: %d\n", argc);
    for (i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
#endif

    int rc = 0;
    int option;
    int option_a = 0;
    char *option_k;

    if (argc == 1) {
        help();
        rc = 1;
        goto exit;
    }

    while ((option = getopt(argc, argv, "k:a")) != -1) {
        switch (option)
        {
        case 'k':
            printf("k kwarg: %s\n", optarg);
            option_k = optarg;
            break;
        case 'a':
            printf("a arg\n");
            option_a = 1;
            break;
        default:
            fprintf(stderr, "Unknown arg: %c\n", optopt);
            rc = 1;
            break;
        }
    }
    printf("Option a = %d\n" "Option k = %s\n", option_a, option_k);

exit:
    return rc;
}
