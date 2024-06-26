#include <stdio.h>

/* У пражнение 1.10. Напишите программу, копирующую вводимые символы в выходной поток с заменой
символа табуляции на \t, символа забоя на \b и каждой обратной наклонной черты на \\. Это сделает
видимыми все символы табуляции и забоя. */
main() {
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\t')
            printf("\\t");
        else if (c == '\b')
            printf("\\b");
        else if (c == '\\')
            printf("\\\\");
        else
            putchar(c);
    }
}
