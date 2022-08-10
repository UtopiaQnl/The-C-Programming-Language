#include <stdio.h>
#include <inttypes.h>

int64_t atoi(const char* string_number);

int main(void)
{
    char array[][20] = {"109283123", "-238424", "-234", "11", "-2345", "999999"};
    for (size_t i = 0; i < 6; i++)
        printf("array[%ld] = %10s | %10s + 10 = %" PRId64 "\n", i, array[i], array[i], atoi(array[i]) + 10);

    return 0;
}

int64_t atoi(const char* s)
{
    int8_t sign = (s[0] == '-') ? -1 : +1; /* знак числа */
    int64_t number = 0;

    for (size_t i = (sign == -1); s[i] != '\0'; i++) /* '0' <= s[i] && s[i] <= '9' --- alt */
        number = 10 * number + (s[i] - '0');

    number = sign * number;
    return number;
}
