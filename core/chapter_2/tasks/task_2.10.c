#include <stdio.h>

int lower(int c);  // если с буква в верхнем регистре - вернёт в нижнем, иначе сам с

/* У пражнение 2.10. Напишите функцию lower, которая переводит большие буквы в малые, используя
 * условное выражение (а не конструкцию if-else). */

int main(void)
{
    for (int i = 65; i < 91; i++)
        printf("%c - %c\n", i, lower(i));
    return 0;
}

int lower(int c)
{
    return ('A' <= c && c <= 'Z') ? (c + 'a' - 'A') : c;
}
