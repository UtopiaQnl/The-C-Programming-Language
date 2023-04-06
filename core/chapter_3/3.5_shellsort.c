#include <stdio.h>

void shellsort(int a[], int size);

int main(void)
{
    int i;
    int arr[25] = {6, -34, 532, -2356, 0, 1, 534, 63, 2,3 ,4 , 5, 6, 7, 8, 9, 0, 46, 7, 76, 4, 34,6};

    putchar('[');
    for (i = 0; i < 25; i++)
        printf("%d%s", arr[i], (i + 1 == 25) ? "]\n": ", ");

    shellsort(arr, 25);

    putchar('[');
    for (i = 0; i < 25; i++)
        printf("%d%s", arr[i], (i + 1 == 25) ? "]\n": ", ");

    return 0;
}

void shellsort(int a[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i++)
            for (int j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap) {
                int temp = a[j];
                a[j] = a[j + gap];
                a[j + gap] = temp;
            }
}
