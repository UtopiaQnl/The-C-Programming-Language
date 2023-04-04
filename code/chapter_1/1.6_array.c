#include <stdio.h>

/* подсчет цифр, символов-разделителей и прочих символов */

main() {
    int c, i, nwhite, nother;
    int ndigit[10];  // = {0} ???
    nwhite = nother = 0;
    for (i = 0; i < 10; i++)  // ???
        ndigit[i] = 0;        // why?!
    while ((c = getchar()) != EOF) {
        if ('0' <= c && c <= '9')
            ndigit[c - '0']++;
        else if (c == ' ' || c == '\t' || c == '\n')
            nwhite++;
        else
            nother++;
    }
    printf("цифры =");
    for (i = 0; i < 10; i++)
        printf(" %d", ndigit[i]);
    printf(", символы-разделители = %d, прочие = %d\n", nwhite, nother);
}
