#include <stdio.h>
#include <inttypes.h>
#include <ctype.h>

int64_t htol(const char* cs);  // переводит строку шестнадцатеричного числа в обычное

/* У пражнение 2.З. Напишите функцию htol(s), которая преобразует последовательность
 * шестнадцатеричных цифр, начинающуюся с 0х или 0Х, в соответствующее целое. Шестнадцатеричными
 * цифрами являются символы 0…9, а…f, А…F. */

int main(void)
{
    const char array[][25] = {"0X1235", "0x@bf", "0xfff", "0XAFBCC", "0x34AFC3", "string", "Jonh", "0x777"};
    for (size_t i = 0; i < 8; i++)
        printf("%-8s = %10" PRId64 "\n", array[i], htol(array[i]));

    return 0;
}

int64_t htol(const char* cs)
{
    if (cs[0] != '0' || toupper(cs[1]) != 'X')
        return -1;

    int64_t result = 0;
    for (size_t i = 2; cs[i] != '\0'; i++) {
        if (isxdigit(cs[i])) {
            if (isdigit(cs[i]))
                result = 0x10 * result + (cs[i] - '0');
            else
                result = 0x10 * result + (toupper(cs[i]) - 'A' + 10);
        }
        else
            return -1;

    }
    return result;
}
