#include <stdio.h>

#define BUFSIZE 100  // буффер *стека для getch и ungetch2

static char buf[BUFSIZE];  // буффер для getch и ungetch2
static int buffp = 0;

int getch(void)  // берёт следующий символ из потока ввода, иначе из буффера, если он не пустой
{
    return (buffp > 0) ? buf[--buffp] : getchar();
}

void ungetch2(int c)  // возвращает символ обратной в *поток (буффер) вывода
{
    if (buffp >= BUFSIZE)
        printf("ungetch2: в буффере слишком много символов!\n");
    else
        buf[buffp++] = c;
}
