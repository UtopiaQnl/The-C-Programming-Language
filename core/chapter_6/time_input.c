#include <stdio.h>
#include <stddef.h>
#include <malloc.h>

typedef int Hour;
typedef int Minute;
typedef int Second;

typedef struct time {
    Hour hour;
    Minute minute;
    Second second;
} Time;

Time* input(void);

int main(void)
{
    Time* time = input();
    if (time)
        printf("now %d:%d:%d\n", time->hour, time->minute, time->second);
    else
        printf("Не удалось инициализировать время(((\n");
    return 0;
}

Time* input(void)
{
    Time* result = (Time*)malloc(sizeof(Time));

    if (result == NULL)
        return result;

    printf("Enter hour: ");
    scanf("%d", &result->hour);
    printf("Enter minute: ");
    scanf("%d", &result->minute);
    printf("Enter second: ");
    scanf("%d", &result->second);

    return result;
}
