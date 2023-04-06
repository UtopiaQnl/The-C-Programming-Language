#include <stdio.h>
#include <inttypes.h>
#include <string.h>

char* itob(int64_t n, char* s, uint16_t base);  // переводит число n в строку по основанию base (base не больше 16)

/* У пражнение 3.5. Напишите функцию itob(n, s, b), которая переводит целое n в строку s,
 * представляющую число по основанию b. В частности, itob(n, s, 16) помещает в s текст числа n в
 * шестнадцатеричном виде. */

int main(void)
{
    char buffer[100];

    int64_t number;
    printf("Введи число: ");
    scanf("%ld", &number);

    for (int i = 2; i < 10; i++) {
        printf("base = %d [number %ld = %s]\n", i, number, itob(number, buffer, i));
    }

    return 0;
}

void reverse(char* s)
{
    int i, j, tmp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        tmp = s[i], s[i] = s[j], s[j] = tmp;
    }
}

char* itob(int64_t n, char* s, uint16_t base)
{
    for (int i = 0; i < 100; i++)
        s[i] = '\0';

    int i = 0;
    int sign;
    if ((sign = n) < 0)
        n = -n;

    do {
        s[i++] = (n % base) + '0';
    } while ((n /= base) != 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';

    reverse(s);

    return s;
}
