#include <stdio.h>

/* У пражнение 1.14. Напишите программу, печатающую гистограммы частот встречаемости вводимых
символов. */

main()
{
    int data[39] = {0};
    int c, i;
    while ((c = getchar()) != EOF) {
        if ('0' <= c && c <= '9')
            data[c - '0' + 26]++;
        else if ('a' <= c && c <= 'z')
            data[c - 'a']++;
        else if ('A' <= c && c <= 'Z')
            data[c - 'A']++;
        else if (c == ' ')
            data[36]++;
        else if (c == '\t')
            data[37]++;
        else if (c == '\n')
            data[38]++;
    }

    for (i = 0; i < 26; i++) {
        printf("'%c': ", i + 97);
        while (data[i]--)
            putchar('-');
        printf("\n");
    }
    for (i = 26; i < 36; i++) {
        printf("'%c': ", i + 48 - 26);
        while (data[i]--)
            putchar('-');
        putchar('\n');
    }
    for (i = 36; i < 39; i++) {
        printf("'%s': ", (i == 36) ? " " : (i == 37) ? "\\t" : "\\n");
        while (data[i]--)
            putchar('-');
        putchar('\n');
    }
}
