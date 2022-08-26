#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

static const int8_t daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

/* day_of_year: определяет день года по месяцу и дню */
int32_t day_of_year(const int32_t year, const int32_t month, int32_t day)
{
    if (!(1 <= month && month <= 12)) {
        printf("error!\nday_of_year: month not in 1..12 value!\n");
        return -1;
    } else if (!(1 <= day && day <= 31)) {
        printf("error!\nday_of_year: day not in 1..31 value!\n");
        return -1;
    }
    const int32_t leap = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    for (size_t i = 0; i < month; ++i)
        day += daytab[leap][i];
    return day;
}

/* month_day: определяет месяц и день по дню года */
void month_day(int32_t year, int32_t year_day, int32_t *month, int32_t *day)
{

    int32_t i;
    const int32_t leap = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    for (i = 1; year_day > daytab[leap][i]; ++i)
        year_day -= daytab[leap][i];
    *month = i;
    *day = year_day;
}
