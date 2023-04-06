#include <stdio.h>

#define MAXLINE 1000 /* максимальная длина вводимой строки */

int getline2(char line[], int limit); /* limit == MAXLINE */
void process_line(char line[], int limit); /* обрабатывает строку, удаляет лишние пробелы и табы */

/* Выводит *красивые строки, без множеств пробелов и тамбов */
int main(void) {
    char line[MAXLINE]; /* текущая строка */
    int len;            /* длина текущей строки */
    int c;
    while ((len = getline2(line, MAXLINE)) > 0) {
        process_line(line, MAXLINE);
    }

    return 0;
}

/* обрабатывает строку; выводит один пробел, если их много */
void process_line(char string[], int lim) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] != ' ' && string[i] != '\t') {
            putchar(string[i]);
            if (string[i + 1] == ' ' || string[i + 1] == '\t') putchar(' ');
        }
    }
}

/* считывает строку в line; возвращает длину вводимой строки i */
int getline2(char line[], int lim) {
    int i, index;
    int c;
    for (index = 0, i = 0; (c = getchar()) != EOF && c != '\n'; i++)
        if (index < lim - 2) {
            line[index] = c;
            index++;
        }

    if (c == '\n') {
        line[index] = c;
        index++;
    }
    line[index] = '\0';

    return i;
}
