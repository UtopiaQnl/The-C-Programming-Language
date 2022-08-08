#include <stdio.h>

/* печатает таблицы температур по Френгейту
 * и Цельсию для fahr = 0, 20, ..., 300 */

main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;  // нижняя граница таблицы температур
    upper = 300;  // верхняя граница
    step = 20;  // шаг

    printf("Table of temperature Far. to Cel.\n");

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("\t  %3.0f %6.1f\n", fahr, celsius); // "%d\t%d\n"
        fahr = fahr + step;
    }
}
