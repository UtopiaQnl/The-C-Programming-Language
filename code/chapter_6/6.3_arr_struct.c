#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS 200

struct key {
    char *word;
    int count;
};

struct key keytab[NKEYS];

size_t getword2(char *, int);
int binsearch(char *, struct key*, const int);

int main(void)
{
    size_t n;
    char word[MAXWORD];

    while (getword2(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;

    for (n = 0; n < NKEYS; ++n)
        if (keytab[n].count > 0)
            printf("%.4d %s\n", keytab[n].count, keytab[n].word);

    return 0;
}

int binsearch(char *word, struct key tab[], const int n)
{
    int low = 0;
    int high = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int cond = strcmp(word, tab[mid].word);
        if (cond < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;

    }
    return -1;
}


size_t getword2(char *word, int lim)
{
    int c;
    char *w = word;

    while (isspace(c = getchar()));

    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }

    for (; --lim > 0; w++)
        if (!isalnum(*w = getchar())) {
            ungetc(*w, stdin);
            break;
        }
    *w = '\0';
    return word[0];
}

