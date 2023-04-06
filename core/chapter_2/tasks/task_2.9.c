#include <stdio.h>

size_t bitcount(unsigned number);

/* У пражнение 2.9. Применительно к числам, в представлении которых использован дополнительный код,
 * выражение х &= (х-1) уничтожает самую правую 1 в х. Объясните, почему. Используйте это наблюдение
 * при написании более быстрого варианта функции bitcount. */

int main(void)
{
    printf("7 - 111\n");
    printf("count = %ld\n", bitcount(7));
    printf("10 - 1010\n");
    printf("count = %ld\n", bitcount(10));
    return 0;
}

size_t bitcount(unsigned number)
{
    size_t i;
    for (i = 0; number != 0; i++)
        number &= (number - 1);

    return i;
}
