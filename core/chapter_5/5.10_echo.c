#include <stdio.h>
#include <stdint.h>

int main(int32_t argc, char *argv[])
{
    while (argc-- > 0)
        printf((argc > 1) ? "%s " : "%s", *argv++);
    printf("\n");
    return 0;
}
