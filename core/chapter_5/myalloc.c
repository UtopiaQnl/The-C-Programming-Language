#include <stddef.h>  // for NULL

#define ALLOCBUFFSIZE 10000  // 10 килобайт

static char allocbuffer[ALLOCBUFFSIZE];
static char *allocbufp = allocbuffer;  // указывает на свободный элемент

/* alloc: возвращает указатель на n байт char'ов */
char *alloc_char(size_t n)
{
    if (allocbuffer + ALLOCBUFFSIZE - allocbufp >= n) {  // запрашиваемая память есть
        allocbufp += n;
        return allocbufp - n;
    }
    return NULL;  // нет запрашиваемой памяти
}


void free_char(char *p)
{
    if (allocbuffer <= p && p < allocbuffer + ALLOCBUFFSIZE)  // указатель выделен в стеке
        allocbufp = p;
}
