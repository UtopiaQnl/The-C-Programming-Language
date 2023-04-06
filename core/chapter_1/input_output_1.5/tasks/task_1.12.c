#include <stdio.h>

#define IN 1 /* внутри слова */
#define OUT 0 /* вне слова */

/* У пражнение 1.12. Напишите программу, которая печатает содержимое своего ввода, помещая по одному
слову на каждой строке. */

main()
{
    int c;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t')
            putchar('\n');
        else
            putchar(c);
    }
}
