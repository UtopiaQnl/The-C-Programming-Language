#include <stdio.h>

size_t len(char *s)
{
    size_t n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}

int main(void)
{
    char array[100] = "some line";  // 9
    char *ptr = "spam!";  // 5
    printf("1. len = %ld (6)\n2. len = %ld (9)\n3. len = %ld (5)\n", len("hello!"), len(array), len(ptr));

    return 0;
}
