#include <stdio.h>
#include <math.h>

#define YMAX 1000
#define XMAX 1000

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

struct point { double x; double y; };

struct rect {
    struct point pt1;
    struct point pt2;
};

/* makepoint: создает точку по координатам x и y */
struct point makepoint(const int x, const int y)
{
    struct point tmp;
    tmp.x = x;
    tmp.y = y;
    return tmp;
}

/* addpoint: складывает точку p1 с точной p2, возвращает результат. */
struct point addpoint(struct point p1, struct point p2)
{
    // т.к в си аргументы передаются по ЗНАЧЕНИЕ, то изменения аргумента в теле фунции, не изменить оригинал
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

/* ptinrect: предикат; проверяет существование точки p в прямоугольнике r */
_Bool ptinrect(struct point p, struct rect r)
{
    return (r.pt1.x <= p.x && p.x <= r.pt2.x) && (r.pt1.y <= p.y && p.y <= r.pt1.y);
}

/* connonrect: канонизация координат прямоугольника */
struct rect connonrect(struct rect r)
{
    r.pt1.x = min(r.pt1.x, r.pt2.x);
    r.pt1.y = min(r.pt1.y, r.pt2.y);
    r.pt2.x = max(r.pt1.x, r.pt2.x);
    r.pt2.y = max(r.pt1.y, r.pt2.y);

    return r;
}

int main(void)
{
    struct point result = makepoint(4, 5);
    printf("point.x - %g\n", result.x);

    struct rect screen;
    struct point middle;

    screen.pt1 = makepoint(0, 0);
    screen.pt2 = makepoint(XMAX, YMAX);

    middle = makepoint(
            (screen.pt1.x + (screen.pt2.x - screen.pt1.x) / 2.0),
            (screen.pt1.y + (screen.pt2.y - screen.pt1.y) / 2.0)
    );

    printf("mid.x - %g\nmid.y - %g\n\n", middle.x, middle.y);

    struct point *pp;  // <- указатель на структуру point

    pp = &middle;

    printf("pp: *(pp).x - %g | *(pp).y - %g\n", pp->x, pp->y);

    return 0;
}
