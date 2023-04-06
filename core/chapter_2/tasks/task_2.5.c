#include <stdio.h>

int any(const char* s1, const char* s2);

/* У пражнение 2.5. Напишите функцию any(s1, s2), которая возвращает либо ту позицию в s1, где стоит
 * первый символ, совпавший с любым из символов в s2, либо -1 (если ни один символ из s1 не совпадает с
 * символами из s2). (Стандартная библиотечная функция strpbrk делает то же самое, но выдает не номер
 * позиции символа, а указатель на символ.) */

int main(void)
{
    const char s_one[] = "some string";
    const char s_two[] = "m0re tr";
    printf("'%s' and '%s'\nfirst idx = %d\n", s_one, s_two, any(s_one, s_two));
    return 0;
}

int any(const char* s1, const char* s2)
{
    for (int i = 0; s1[i] != '\0'; i++)
        for (int j = 0; s2[j] != '\0'; j++)
            if (s1[i] == s2[j])
                return i;
    return -1;
}
