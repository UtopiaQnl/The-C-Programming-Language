#include <stdio.h>
#include "getline2.c"
#include "4.2_atof.c"

#define MAXLINE 1000

int main(void)
{
    double sum, atof(char*);
    char line[MAXLINE];
    int getline2(char*, int);
    while (getline2(line, MAXLINE) > 0) {
        printf("\t%g\n", sum += atof(line));
    }
    return 0;
}
