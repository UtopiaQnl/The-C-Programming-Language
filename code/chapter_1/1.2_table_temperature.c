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

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.);
        printf("%3.0f %6.1f\n", fahr, celsius); // "%d\t%d\n"
        fahr = fahr + step;
    }
}
