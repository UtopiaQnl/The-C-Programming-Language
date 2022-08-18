#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100

/* калькулятор с обратной польской записью */
int main(void)
{
    int type;
    double second_operator;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                second_operator = pop();
                push(pop() - second_operator);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                second_operator = pop();
                if (second_operator != 0.0)
                    push(pop() / second_operator);
                else
                    printf("ошибка: деление на нуль!\n");
                break;
            case '\n':
                printf("---> %.8g\n", pop());
                break;
            default:
                printf("ошибка: неизвестная операция!\n");
                break;
        }
    }
    return 0;
}
