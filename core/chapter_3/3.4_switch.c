#include <stdio.h>

int main(void)  // подсчет цифр, символов-разделителей и прочих символов
{
    int c, i, nwhite, nother, ndigit[10] = {0};

    nwhite = nother = 0;
    while ((c = getchar()) != EOF) {
        switch (c) {
            case '0'...'9':  // case '0': case: '1': case: '2': case: '3'...case: '8' case: '9':
                ndigit[c - '0']++;
                break;
            case ' ': case '\t': case '\n':  // проверят на случай если c это пробел, там и перевод на след. строку
                nwhite++;
                break;
            default:
                nother++;
                break;
        }
    }

    printf("цифры :");
    for (i = 0; i < 10; i++)
        printf(" %d", ndigit[i]);
    printf(", символов-разделителей = %d, прочих = %d\n", nwhite, nother);
}
