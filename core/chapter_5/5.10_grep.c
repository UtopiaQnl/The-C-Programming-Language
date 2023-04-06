#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define MAXLINE 1000

size_t take_line(char *line, const int64_t limit)
{
    size_t i;
    int32_t letter;
    for (i = 0; i < limit - 1 && (letter = getchar()) != EOF && letter != '\n'; ++i)
        line[i] = letter;
    if (letter == '\n')
        line[i++] = letter;
    line[i] = '\0';
    return i;
}

int32_t main(const int32_t argc, char *argv[])
{
    char line[MAXLINE];
    int32_t found = 0;

    if (argc != 2) {
        printf("Ошибка! Вы не ввели образец для поиска.\n");
        return -1;
    }

    while (take_line(line, MAXLINE) > 0) {
        if (strstr(line, argv[1]) != NULL) {
            printf("%s", line);
            found++;
        }
    }

    return found;
}
