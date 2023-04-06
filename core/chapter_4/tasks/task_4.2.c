#include <ctype.h>
#include <math.h>

double atof(char* s)
{
    double value, power, exp;
    int i, sign, sub_sign;

    for (i = 0; isspace(s[i]); i++);  // пропуск 'пустых' символов
    sign = (s[i] == '-') ? -1 : +1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (value = 0.0; isdigit(s[i]); i++)
        value = 10.0 * value + (s[i] - '0');

    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++) {
        power *= 10.0;
        value = 10.0 * value + (s[i] - '0');
    }

    if (s[i] == 'e' || s[i] == 'E')
        i++;

    sub_sign = (s[i] == '-') ? -1 : +1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (exp = 0; isdigit(s[i]); i++)
        exp = 10.0 * exp + (s[i] - '0');

    double result = sign * value / power;
    if (sub_sign < 0)
        return result / pow(10.0, exp);
    else
        return result * pow(10.0, exp);
}
