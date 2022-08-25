#include <stdio.h>
#include <string.h>

#define MAXLINES 5000  /* максимальная число строк */

char *line_ptr[MAXLINES];  /* указатели на строки */

int readlines(char *line_ptr[], int count_lines);
void print_lines(char *line_ptr[], int count_lines);
void qsort(char *line_ptr[], int left, int right);

/* сортировка строк */
int main(void)
{
    int count_lines;
    if ((count_lines = readlines(line_ptr, MAXLINES)) >= 0) {
        qsort(line_ptr, 0, count_lines - 1);
        print_lines(line_ptr, count_lines);
        return 0;
    }
    printf("ошибка: слишком много строк!\n");
    return 1;
}

#define MAXLINE 1000

char *alloc_char(size_t n);
void free_char(char *p);

int getline2(char *s, int limit)
{
    int i, c;
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* readlines: читает строки */
int readlines(char *linelist[], int maxlines)
{
    int len;
    int n_lines;
    char *p;
    char line[MAXLINE];

    n_lines = 0;
    while ((len = getline2(line, MAXLINE)) > 0) {
        if (n_lines >= MAXLINES || (p = alloc_char(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0'; /* убираем \n */
            strcpy(p, line);
            line_ptr[n_lines++] = p;
        }
    }
    return n_lines;
}

/* print_lines: выводит строки на экран */
void print_lines(char *line_ptr[], int count_lines)
{
    while (count_lines-- > 0)
        printf("%s\n", *line_ptr++);
}

void swap(char *v[], int i, int j)
{
    char *tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

/* qsort: сортирует v[left]...v[right] по возрастанию */
void qsort(char *v[], int left, int right)
{
    int i, last;
    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) > 0)
            swap(v, ++last, i);
    swap(v, left, last - 1);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}
