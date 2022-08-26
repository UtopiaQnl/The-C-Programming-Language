#include <stdio.h>
#include <stdint.h>

int main(int32_t argc, char *argv[])
{
    for (size_t i = 0; i < argc; ++i)
        printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
    printf("\n");
    return 0;
}
