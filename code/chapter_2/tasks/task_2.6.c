#include <stdio.h>

#define MAXLINE 1000 /* максимальная длина строки */

size_t getline2(char line[], size_t limit);

/* for (i = 0; i < lim-1 && (с = getchar()) != EOF && с != '\n'; ++i)
 * У пражнение 2.2. Напишите цикл, эквивалентный приведенному выше fоr-циклу, не пользуясь операторами
 * && и ||. */

int main(void)
{
    char line[MAXLINE];
    int len; /* длина текущей строки */
    while ((len = getline2(line, MAXLINE)) > 0)
        printf("len: %d - %s", len, line);

    return 0;
}

size_t getline2(char* line, size_t lim)
{
    size_t i;
    int c;
    for (i = 0; ( (i < lim - 1) + ((c = getchar()) != EOF) + (c != '\n') ) == 3; ++i)
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}
