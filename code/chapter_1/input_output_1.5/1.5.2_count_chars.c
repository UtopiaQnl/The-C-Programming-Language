#include <stdio.h>

/* подсчет вводимых символов; 2-я версия */
main() {
    double nc;
    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("count = %.0f\n", nc);
}
