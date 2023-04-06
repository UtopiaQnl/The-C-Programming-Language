#include <stdio.h>
#include <string.h>

void reverse(char* s, int l, int r);

/* У пражнение 4.13. Напишите рекурсивную версию функции reverse(s), переставляющую элементы строки
 * в ту же строку в обратном порядке. */

int main(void)
{
    char arr[][15] = {"abraca", "some ", "sometirng", "sdf df as"};
    for (int i = 0; i < 4; i++) {
        printf("%s -> ", arr[i]);
        reverse(arr[i], 0, strlen(arr[i]) - 1);
        printf("%s\n", arr[i]);
    }
    return 0;
}

void reverse(char* s, int l, int r)
{
    if (l >= r)
        return;
    int tmp = s[l];
    s[l] = s[r];
    s[r] = tmp;
    reverse(s, l + 1, r - 1);
}
