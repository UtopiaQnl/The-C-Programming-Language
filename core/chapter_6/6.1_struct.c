#include <stdio.h>
#include <math.h>

struct point {
    int x;
    int y;
} a, b, c;

struct ppoint { int* x; int* y; } x, y;

int main(void)
{
    a.x = 5;
    a.y = 10;

    printf("a.x - %d\na.y - %d\n", a.x, a.y);

    x.x = &a.x;
    x.y = &a.y;

    printf("*x.x - %d\n*x.y - %d\n\n", *x.x, *x.y);

    struct dot { double x; double y; } p;
    p.x = 4.0;
    p.y = 3.0;

    printf("p.x - %f\np.y - %f\n\n", p.x, p.y);

    double dist;
    dist = sqrt(p.x * p.x + p.y * p.y);

    printf("dist - %f\n", dist);

    struct rect { struct dot pt1; struct dot pt2; } screen;

    screen.pt1.x = 1.0;
    screen.pt1.y = 1.0;

    screen.pt2.x = 3.0;
    screen.pt2.y = 3.0;

    printf("screen is rectangle.\nscreen.point_1.x - %f | screen.point_1.y - %f\n", screen.pt1.x, screen.pt1.y);
    printf("screen.point_2.x - %f | screen.point_2.y - %f\n", screen.pt2.x, screen.pt2.y);
    printf("S (screen) == %f\n", (screen.pt2.y - screen.pt1.y) * (screen.pt2.x - screen.pt1.x));

    return 0;
}

