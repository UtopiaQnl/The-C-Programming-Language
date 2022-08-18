#include <stdio.h>
#include "calc.h"

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

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
