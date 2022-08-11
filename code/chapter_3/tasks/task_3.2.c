#include <stdio.h>

char* escape(char* s, const char* t);  // копирует из t в s; s достаточно большой. эскейп-последовательности видны

/* У пражнение 3.2. Напишите функцию escape(s, t), которая при копировании текста из t в s преобразует
 * такие символы, как новая строка и табуляция в "видимые последовательности символов" (вроде \n и \t).
 * Используйте инструкцию switch. Напишите функцию, выполняющую обратное преобразование эскейп-
 * последовательностей в настоящие символы. */

int main(void)
{
    char s[100] = "some string lol!";
    char from[] = "ABCD1\b238\t\t someth\ning?()\n";
    printf("\"some string lol!\" + \"ABCD1\\b238\\t\\t someth\\ning?()\\n\" = %s\n", escape(s, from));
    return 0;
}

/* копирует t в s, при этом все эскейп-последовательности становятся "сырыми"; s достаточно большой */
char* escape(char*s, const char* t)
{
    int i, j;
    int c;  // символ
    i = j = 0;
    while (s[i] != '\0')  // находит конец строки s
        i++;
    while ((c = t[j++]) != '\0') {
        switch (c) {
            case '\n':
                s[i++] = '\\';
                s[i++] = 'n';
                break;
            case '\t':
                s[i++] = '\\';
                s[i++] = 't';
                break;
            case '\b':
                s[i++] = '\\';
                s[i++] = 'b';
                break;
            default:
                s[i++] = c;
                break;
        }
    }
    s[i] = '\0';

    return s;
}
