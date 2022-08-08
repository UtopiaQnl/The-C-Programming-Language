#include <stdio.h>
/* копирование ввода на вывод; 1-я версия */
main()
{
    int c;
    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}
