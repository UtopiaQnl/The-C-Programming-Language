#include <stdio.h>

static void swap(int* a, int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void qsort(int* arr, int left, int right)
{
    if (left >= right)
        return;  // if (len(arr) < 2)

    swap(arr, left, (left + right) / 2);
    int last = left;
    for (int i = left + 1; i <= right; i++)
        if (arr[i] < arr[left])
            swap(arr, ++last, i);
    swap(arr, left, last);
    qsort(arr, left, last - 1);
    qsort(arr, last + 1, right);
}
