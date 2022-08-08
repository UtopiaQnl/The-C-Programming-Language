#include <stdio.h>

/* У пражнение 1.9. Напишите программу, копирующую символы ввода в выходной поток и заменяющую
стоящие подряд пробелы на один пробел. */
main()
{
    int fl, c;

    fl = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (fl) continue;
            else
                fl = 1;
        } else
            fl = 0;
        putchar(c);
    }
}
