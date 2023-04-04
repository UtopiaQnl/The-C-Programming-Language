#include <stdio.h>

/* подсчет строк входного потока */
main() {
    int c, nl;
    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n') ++nl;
    printf("count line = %d\n", nl);
}
