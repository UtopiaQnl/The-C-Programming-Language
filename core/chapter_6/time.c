#include <stdio.h>
#include <inttypes.h>

typedef int Hour;
typedef int Minute;
typedef int Second;

typedef struct time {
    Hour hour;
    Minute minute;
    Second second;
} Time;

Time addminutes(Time, Minute);

int main(void)
{
    Hour h = 16;
    Minute m = 14;
    Second s = 56;

    Time current_time = {h, m, s};

    printf("%d:%d:%d\n", current_time.hour, current_time.minute, current_time.second);

    Time result = addminutes(current_time, 56);
    printf("+56m = %d:%d:%d\n", result.hour, result.minute, result.second);

    result = addminutes(current_time, 4);
    printf("+4m = %d:%d:%d\n", result.hour, result.minute, result.second);

    result = addminutes(current_time, 100);
    printf("+100m = %d:%d:%d\n", result.hour, result.minute, result.second);

    return 0;
}

Time addminutes(Time t, Minute m)
{
    Hour h, d;

    t.minute += m;

    if (t.minute >= 60) {
        h = t.minute / 60;
        t.minute -= h * 60;
        t.hour += h;
    }

    if (t.hour >= 24) {
        d = t.hour / 24;
        t.hour -= d * 24;
    }

    return t;
}
