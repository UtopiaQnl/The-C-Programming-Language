#include <stdio.h>

int power(int m, int n);  // int power(int, int);

/* тест функции power */
main() {
    int i;
    for (i = 0; i < 10; i++)
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    return 0;
}

/* возводит base в n-ю степень; n >= 0; версия 2 */
int power(int base, int n) {
    int p;
    for (p = 1; n > 0; n--)
        p = p * base;
    return p;
}
