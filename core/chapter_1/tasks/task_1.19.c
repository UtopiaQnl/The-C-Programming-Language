#include <stdio.h>

#define MAXLINE 1000 /* максимальная длина вводимой строки */

/* У пражнение 1.19. Напишите функцию reverse(s), размещающую символы в строке s в обратном порядке.
Примените ее при написании программы, которая каждую вводимую строку располагает в обратном порядке. */

int getline2(char line[], int limit); /* limit == MAXLINE */
void reverse(char string[], int length);

int main(void) {
    char line[MAXLINE]; /* текущая строка */
    int len;            /* длина текущей строки */
    while ((len = getline2(line, MAXLINE)) > 0) {
        reverse(line, len);
        printf("%s", line);
    }

    return 0;
}

/* переворачивает строку s */
void reverse(char s[], int len) {
    for (int i = 0; i < len / 2; i++) {
        int tmp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = tmp;
    }
}

/* считывает вводимую строку в line; возвращает длину введённой строки */
int getline2(char line[], int lim) {
    int index, i;
    int c;
    for (index = 0, i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        if (index < lim - 2) {
            line[index] = c;
            index++;
        }
    }
    if (c == '\n') {
        line[index] = c;
        index++;
    }
    line[index] = '\0';

    return i;
}
