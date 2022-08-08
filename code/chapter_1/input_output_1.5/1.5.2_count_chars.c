#include <stdio.h>

/* подсчет вводимых символов; 1-я версия */
main()
{
    long nc;
    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("count = %ld\n", nc);
}
