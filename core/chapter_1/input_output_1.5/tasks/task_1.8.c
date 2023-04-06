#include <stdio.h>

/* Упражнение 1.8. Напишите программу для подсчета пробелов, табуляций и новых строк. */
main()
{
    long count_tabs, count_spaces, count_lines;
    int c;

    count_tabs = count_lines = count_spaces = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            count_spaces++;
        else if (c == '\n')
            count_lines++;
        else if (c == '\t')
            count_tabs++;
    }

    printf("tabs: %ld\nspaces: %ld\nlines: %ld\n", count_tabs, count_spaces, count_lines);
}
