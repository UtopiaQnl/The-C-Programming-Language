#include <stdio.h>
#include <string.h>

void reverse(char* s);

int main(void)
{
    char arr[4][50] = {"some", "abracadabra", "123456789", "hello, world!"};

    for (int i = 0; i < 4; i++) {
        printf("%15s -> ", arr[i]);
        reverse(arr[i]);
        printf("%s\n", arr[i]);
    }

    return 0;
}

void reverse(char* s)
{
    int i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        int tmp = s[j];
        s[j] = s[i];
        s[i] = tmp;
    }
}
