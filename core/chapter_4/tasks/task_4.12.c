#include <stdio.h>

void itoa(int n, char* s);

/* Упражнение 4.12. Примените идеи, которые мы использовали в рrintd, длянаписания рекурсивной версии
 * функции itoa; иначе говоря, преобразуйте целое число в строку цифр с помощью рекурсивной программы. */

static int idx = 0;

int main(void)
{
    char s[100];
    int arr[10] = {-2345, 123, -123, 234, 1119141, -1, 0, 999, 98341, -9128323};
    for (int i = 0; i < 10; i++) {
        printf("int %d = ", arr[i]);
        itoa(arr[i], s);
        printf("%s\n", s);
        idx = 0;
        for (int i = 0; i < 100; i++)
            s[i] = '\0';
    }
    return 0;
}


void itoa(int n, char* s)
{
    if (n / 10)
        itoa(n / 10, s);
    else if (n < 0)
        s[idx++] = '-';
    s[idx++] = ( (n % 10 > 0) ? n % 10 : -(n % 10)) + '0';
}
