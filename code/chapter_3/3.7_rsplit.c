#include <stdio.h>
#include <string.h>

int rsplit(char* s);

int main(void)
{
    char line[100] = "some string      ";
    printf("'%s' = ", line);
    int count = rsplit(line);
    printf("'%s' (удалено %d)\n", line, count);
    return 0;
}

/* удаляет пробелы, табы, переносы строк с права */
int rsplit(char* s)
{
    int i;
    int len = strlen(s);
    for (i = len - 1; i >= 0; i--)
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
            break;
    s[++i] = '\0';
    return len - i;
}
