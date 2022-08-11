#include <stdio.h>
#include <string.h>

void squeeze(char* s, int c);
size_t getline2(char* line, size_t limit);
char* strcat2(char* to, const char* from); // склеивает строки: from в to; to достаточно большая

int main(void)
{
    char line[] = "some string sss abc";
    printf("len: %ld - '%s'\n", strlen(line), line);
    squeeze(line, 's');
    printf("len: %ld - '%s'\n", strlen(line), line);

    char s[100] = "hello,";
    printf("%s + %s = %s\n", "hello,", "WORLD!)", strcat2(s, "WORLD!)"));
    return 0;
}

char* strcat2(char* s, const char* t)
{
    size_t i, j;
    i = j = 0;
    while (s[i] != '\0') // нахождение конца строки s
        i++;
    while ((s[i++] = t[j++]) != '\0');  // копирование из t в s
    return s;
}

size_t getline2(char* line, size_t lim)
{
    size_t i;
    int c;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';

    return i;
}

/* squeeze: удаляет все с из s (отправляет их в конец)*/
void squeeze(char* s, int c)
{
    int i, j;
    int count = 0;
    for (i = j = 0; s[i] != '\0'; i++) {
        if (s[i] != c)
            s[j++] = s[i];
        else
            count++;
    }
    s[i-count] = '\0';
}
