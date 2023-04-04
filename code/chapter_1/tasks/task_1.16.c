#include <stdio.h>

#define MAXLINE 10 /* максимальный размер вводимой строки */

int getline2(char line[], int maxline);  // getline2(char, MAXLINE);
void copy(char to[], char from[]);

/* печать самой длинной строки */
int main(void) {
    int len;               /* длина текущей строки */
    int max;               /* длина максимальной из просмотренныйх строк */
    char line[MAXLINE];    /* текущая строка */
    char longest[MAXLINE]; /* самая длинная строка */
    max = 0;
    while ((len = getline2(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) /* была ли хоть одна строка? */
        printf("most longest (len - %d): %s", max, longest);

    return 0;
}

/* getline2: читает строку в s, возвращает длину */
int getline2(char s[], int lim) {
    int c, i, index;
    index = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
        if (index < lim - 2) {
            s[index] = c;
            index++;
        }

    if (c == '\n') {
        s[index] = c;
        index++;
    }
    s[index] = '\0';
    return i;
}

/* copy: копирует из 'from' в 'to'; to достаточно большой */
void copy(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        i++;
}
