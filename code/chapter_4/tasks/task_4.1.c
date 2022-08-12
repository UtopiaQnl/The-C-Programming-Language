#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int rstrindex(const char *s, const char* t);
int getline2(char* s, int limit);

char pattern[] = "iridium";

/* У пражнение 4.1. Напишите функцию strindex(s, t), которая выдает позицию самого правого вхождения
 * t в s или -1, если вхождения не обнаружено. */

int main(void)
{
    char line[MAXLINE];
    while (getline2(line, MAXLINE) > 0) {
        if (rstrindex(line, pattern) > 0)
            printf("%s", line);
    }
    return 0;
}

int rstrindex(const char* s, const char* t)
{
    int j, k;
    int len_t = strlen(t);
    for (int i = strlen(s) - 1; i >= 0; i--) {
        for (j = i, k = 0; (j >= 0 && t[k] != '\0') && s[j] == t[len_t - k - 1]; j--, k++);
        if (k == len_t)
            return i;
    }
    return -1;
}

int getline2(char* s, int lim)
{
    int i, c;
    int index = 0;
    for (i = 0; index < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        if (index < lim - 1)
            s[index++] = c;
    if (c == '\n')
        s[index++] = c;
    s[index] = '\0';
    return i;
}
