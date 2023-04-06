#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float FahrToCel(float);

int main() {
    for (int fahr = 0; fahr <= UPPER; fahr += STEP)
        printf("%3d %6.1f\n", fahr, FahrToCel(fahr));
    return 0;
}

float FahrToCel(float fahr) {
    return fahr * 1.8 + 32;
}
