#include <stdio.h>

long binary_search(const long n, const long arr[], const long size);

/* У пражнение 3.1. В нашей программе бинарного поиска внутри цикла осуществляются две проверки, хотя
 * могла быть только одна (при увеличении числа проверок вне цикла). Напишите программу, предусмотрев в
 * ней одну проверку внутри цикла. Оцените разницу во времени выполнения. */

int main(void)
{
    const long arr[12] = {-1, 0, 0, 2, 4, 5, 5, 7, 9, 13, 25, 31};
    long number = 0;
    printf("idx %ld - %ld\n", number, binary_search(number, arr, 12));
    return 0;
}

long binary_search(const long n, const long arr[], const long size)
{
    if (size == 0) return -1;

    long l = 0;
    long r = size;
    while (l + 1 < r) {
        long mid = l + (r - l) / 2;

        if (arr[mid] > n)
            r = mid;
        else
            l = mid;
    }
    return (arr[l] == n) ? l : -1;
}
