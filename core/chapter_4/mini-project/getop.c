#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char* s)
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c;  // c не число

    i = 0;
    if (isdigit(c))  // накапливаем целую часть числа
        while (isdigit(s[++i] = c = getch()));

    if (c == '.')  // накапливаем дробную часть числа
        while (isdigit(s[++i] = c = getch()));

    s[i] = '\0';
    if (c != EOF)
        ungetch2(c);
    return NUMBER;
}
