#include <stdio.h>
/* копирование ввода на вывод; 3-я версия */
main() {
    int c;
    while ((c = getchar()) != EOF) {
        printf("%c [EOF] = %c (%d)\n", c, EOF, EOF);
    }
}
