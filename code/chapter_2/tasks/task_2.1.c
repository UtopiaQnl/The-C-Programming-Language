#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("byte of char = %ld\n", sizeof(char));
    printf("\tmin char = %d\n\tmax char = %d\n", CHAR_MIN, CHAR_MAX);
    printf("\tmin unsigned char = %d\n\tmax unsigned char = %d\n", 0, UCHAR_MAX);
    printf("\tmin signed char = %d\n\tmax signed char = %d\n\n", SCHAR_MIN, SCHAR_MAX);

    printf("byte of int = %ld\n", sizeof(int));
    printf("\tmin int = %d\n\tmax int = %d\n", INT_MIN, INT_MAX);
    printf("\tmin unsigned int = %d\n\tmax unsigned int = %d\n", 0, UINT_MAX);
    printf("\tmin signed int = %d\n\tmax signed int = %d\n\n", INT_MIN, INT_MAX);

    printf("byte of short = %ld\n", sizeof(short));
    printf("\tmin short = %d\n\tmax short = %d\n", SHRT_MIN, SHRT_MAX);
    printf("\tmin unsigned short = %d\n\tmax unsigned short = %d\n", 0, USHRT_MAX);
    printf("\tmin signed short = %d\n\tmax signed short = %d\n\n", SHRT_MIN, SHRT_MAX);

    printf("byte of long = %ld\n", sizeof(long));
    printf("\tmin long = %ld\n\tmax long = %ld\n", LONG_MIN, LONG_MAX);
    printf("\tmin unsigned long = %d\n\tmax unsigned long = %lu\n", 0, ULONG_MAX);
    printf("\tmin signed long = %ld\n\tmax signed long = %ld\n\n", LONG_MIN, LONG_MAX);

    printf("byte of long long = %ld\n", sizeof(long long));
    printf("\tmin long long = %lld\n\tmax long long = %lld\n", LLONG_MIN, LLONG_MAX);
    printf("\tmin unsigned long = %d\n\tmax unsigned long = %llu\n", 0, ULLONG_MAX);
    printf("\tmin signed long = %lld\n\tmax signed long = %lld\n\n", LLONG_MIN, LLONG_MAX);

    return 0;
}
