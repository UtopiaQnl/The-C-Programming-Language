#include <stdio.h>
#include <string.h>
#define MAXLINE 1000  // максимальная длина строки

int getline2(char* line, int max);
int strindex(char* source, char* searchfor);

char pattern[] = "ould";  // образен поиска

/* найти все строки содержащие образец */
int main(void)
{
    char line[MAXLINE];  // текущая строка
    int found = 0;  // сколько было найдено строк с образцом
    while (getline2(line, MAXLINE) > 0) {
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    }
    return found;
}

/* getline2: читает строку в s, возвращает длину */
int getline2(char* s, int lim)
{
    int i, c;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strindex: вычисляет место t в s или выдает -1, если t нет в s */
int strindex(char* s, char* t)
{
    int j, k;
    int lt = strlen(t);
    for (int i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; (t[k] != '\0' && s[j] != '\0') && s[j] == t[k]; j++, k++);
        if (k == lt)
            return i;
    }
    return -1;
}
