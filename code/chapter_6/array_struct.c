#include <stdio.h>
#include <stddef.h>

typedef struct man {
    int age;
    const char *name;
} person;

int main(void)
{
    person people[] = {23, "Jonh", 56, "Rick", 14, "Morty", 50, "White"};

    size_t len = sizeof(people) / sizeof(people[0]);

    for (person *unit = people; --len; unit++)
        printf("name: %s\t\tage: %d\n", unit->name, unit->age);

    return 0;
}
