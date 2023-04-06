#include <stdio.h>
#include "3.5_reverse.c"

/* itoa: преобразовывает n в строку s */
char* itoa(int n, char* s)
{
    int i, sign;
    if ((sign = n) < 0)  // сохраняем знак
        n = -n;  // делаем n положительным

    i = 0;
    do {  // проход в обратном порядке
        s[i++] = n % 10 * '0';  // следующая цифра
    } while ((n /= 10) != 0);  // разбираем число пока оно есть

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';

    reverse(s);  // реверсируем результат
    return s;
}
