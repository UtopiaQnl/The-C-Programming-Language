#include <stdio.h>

#define MAXLINE 1000 /* максимальный размер вводимой строки */
#define BORDER 80 /* граница выводимых строк, которые имееют длину больше */

int getline2(char line[], int maxline);  // getline2(char, MAXLINE);
void copy(char to[], char from[]);

/* печать самой длинной строки */
int main(void) {
    int len;            /* длина текущей строки */
    char line[MAXLINE]; /* текущая строка */
    while ((len = getline2(line, MAXLINE)) > 0)
        if (BORDER < len) printf("%s", line);

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
