#include <stdio.h>
#include "calc.h"

#define MAXVAL 100

static int sp = 0;  // статик для того, чтобы этих переменных не было в других файлах
static double val[MAXVAL];  // статик ограничивает области видимости этой переменной концом файла, т.е. он видет только в этом файле

/* push: положить значение f в стек */
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("ошибка: стек полон! %g не помещается.\n", f);
}

/* pop: взять с вершины стека и выдать как результат */
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("ошибка: стек пуст!\n");
        return 0.0;
    }
}
