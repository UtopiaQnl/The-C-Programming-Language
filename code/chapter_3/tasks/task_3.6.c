#include <stdio.h>
#include <string.h>

void itoa(int n, char* s, int buffer);

int main(void)
{
    char buffer[100];
    for (int i = 2; i < 8; i++) {
        itoa(346, buffer, i);
        printf("i = %d (346) = |%s|\n", i, buffer);
    }
    return 0;
}

void reverse(char* s)
{
    int i, j, tmp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
        tmp = s[i], s[i] = s[j], s[j] = tmp;
}

void itoa(int n, char* s, int buf)
{
    int i = 0;
    int sign;
    if ((sign = n) < 0)
        n = -n;

    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';

    for (; i < buf; i++)
        s[i] = ' ';

    s[i] = '\0';

    reverse(s);
}
