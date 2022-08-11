#include <stdio.h>

char* squeeze(char* s, const char* t);

/* У пражнение 2.4. Напишите версию функции squeeze(s1, s2), которая удаляет из s1 все символы,
 * встречающиеся в строке s2.  */

int main(void)
{
    char line[] = "abricos some abc sring";
    printf("%s - 'abcs'\n", line);
    squeeze(line, "abcs");
    printf("'%s'\n", line);
    return 0;
}

char* squeeze(char* s, const char* t)
{
    int i, j;
    int count = 0;
    for (int k = 0; t[k] != '\0'; k++) {
        for (i = j = 0; s[i] != '\0'; i++) {
            if (s[i] != t[k])
                s[j++] = s[i];
            else
                count++;
        }
        s[i] = '\0';
    }
    s[i - count] = '\0';
    return s;
}
