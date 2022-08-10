#include <stdio.h>
#include <inttypes.h>

int64_t atoi(const char* string_number);  // переводит строку в число
int32_t lower(int32_t character);  // принимает символ, возвращает тот же символ но в нижнем регисте

int main(void)
{
    size_t i;

    char array[][20] = {"109283123", "-238424", "-234", "11", "-2345", "999999"};
    for (i = 0; i < 6; i++)
        printf("array[%ld] = %10s | %10s + 10 = %" PRId64 "\n", i, array[i], array[i], atoi(array[i]) + 10);

    putchar('\n');

    for (i = 97; i < 123; i++)
        printf("%c - %c\n", (char)i, lower(i));

    putchar('\n');

    for (i = 65; i < 91; i++)
        printf("%c - %c\n", (char)i, lower(i));

    return 0;
}

int32_t lower(int32_t num)
{
    if ('A' <= num && num <= 'Z')
        return num + 'a' - 'A';
    return num;
}

int64_t atoi(const char* cs)
{
    int8_t sign = (cs[0] == '-') ? -1 : +1; /* знак числа */
    int64_t number = 0;

    for (size_t i = (sign == -1); cs[i] != '\0'; i++) /* '0' <= s[i] && s[i] <= '9' --- alt */
        number = 10 * number + (cs[i] - '0');

    number = sign * number;
    return number;
}
