#include <stdio.h>

int getline2(char* s, int lim)
{
    int i, c;
    int index = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
        if (index < lim - 1)
            s[index++] = c;
    if (c == '\n')
        s[index++] = c;
    s[index] = '\0';
    return i;
}
