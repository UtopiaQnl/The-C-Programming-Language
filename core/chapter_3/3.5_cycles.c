#include <stdio.h>
#include <ctype.h>

int atoi(const char* s);

int main(void)
{
    const char arr[][40] = {"some", "123", "+2345", "-sdfg", "23+2345", " +34", "\t+345"};
    for (int i = 0; i < 7; i++)
        printf("'%s' - int(%d)\n", arr[i], atoi(arr[i]));
    return 0;
}

/* atoi: преобразование s в целое число */
int atoi(const char* s)
{
    int i, n, sign;


    for (i = 0; isspace(s[i]); i++);  // игнорирование "пустных" символов
    sign = (s[i] == '+') ? +1 : -1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');

    return sign * n;
}
