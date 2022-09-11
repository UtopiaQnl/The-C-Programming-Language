#include <stdio.h>

struct {
    unsigned int one : 1;
    unsigned int two : 1;
    unsigned int three : 1;
    unsigned int four : 1;
    unsigned int five : 1;
} flags;

int main(void)
{
    printf("sizeof(flags) = %ld\n", sizeof(flags));
    printf("flags.one = %d\n", flags.one);
    printf("flags.two = %d\n", flags.two);
    printf("flags.three = %d\n", flags.three);

    flags.one = 1;
    flags.three = 1;

    printf("flags.one = %d\n", flags.one);
    printf("flags.two = %d\n", flags.two);
    printf("flags.three = %d\n", flags.three);
    return 0;
}
