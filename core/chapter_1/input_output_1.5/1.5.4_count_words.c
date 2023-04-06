#include <stdio.h>

#define IN 1  /* внутри слова */
#define OUT 0 /* вне слова */

/* подсчет строк, слов и символов */
main() {
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        nc++;
        if (c == '\n') nl++;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (OUT == state) {
            state = IN;
            nw++;
        }
    }
    printf("lines: %d\nwords: %d\ncharacters: %d\n", nl, nw, nc);
}
