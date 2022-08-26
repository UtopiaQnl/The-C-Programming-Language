#include <stdint.h>

char *month_name(uint8_t number)
{
    static char *name[] = {
        "Неверный месяц",
        "Январь", "Февраль", "Март",
        "Апрель", "Май", "Июнь",
        "Июль", "Август", "Сентябрь",
        "Октябрь", "Ноябрь", "Декабрь"
    };

    return (1 <= number && number <= 12) ? name[number] : name[0];
}
