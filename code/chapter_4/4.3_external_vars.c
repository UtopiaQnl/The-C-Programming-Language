#include <stdio.h>
#include <stdlib.h>  // для atof()

#define MAXOP 100  // максимальный размер для операнда
#define NUMBER '0'  // признак что след. элемент - число

int getop(char*);
void push(double);
double pop(void);

/* калькулятор с обратной польской записью */
int main(void)
{
    int type;
    double op2;
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
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("ошибка: деление на нуль!\n");
                break;
            case '\n':
                printf("   %.8g\n", pop());
                break;
            default:
                printf("ошибка: неизвестная операция!\n");
                break;
        }
    }
    return 0;
}

#define BUFFERSIZE 100  // буффер *стека для getch и ungetc

char buffer[BUFFERSIZE];  // буффер для getch и ungetc
int buffer_p = 0;

int getch(void)  // берёт следующий символ из потока ввода, иначе из буффера, если он не пустой
{
    return (buffer_p > 0) ? buffer[--buffer_p] : getchar();
}

void ungetc2(int c)  // вернуть символ c обратно в *поток вывода
{
    if (buffer_p >= BUFFERSIZE)
        printf("ungetc: в буффере слишком много символов!\n");
    else
        buffer[buffer_p++] = c;
}

#include <ctype.h>

int getch(void);
void ungetc2(int);

/* getop: получает следующий оператор или опренд */
int getop(char* s)
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;  // не число
    i = 0;
    if (isdigit(c))  // накапливаем целую часть числа
        while (isdigit(s[++i] = c = getch()));

    if (c == '.')  // накапливаем дробную часть числа
        while (isdigit(s[++i] = c = getch()));

    s[i] = '\0';
    if (c != EOF)
        ungetc2(c);
    return NUMBER;
}

#define MAXVAL 100  // максимальная глубина стека

int sp = 0;  // статус заполнённости стека - следующая позиция в стеке.
double val[MAXVAL];  // стек на основе массива

/* push: положить значение f в стек */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("ошибка: стек полон! %g не помещается.\n", f);
}

/* pop: взять с вершины стека и выдать как результат */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("ошибка: стек пуст!\n");
        return 0.0;
    }
}

