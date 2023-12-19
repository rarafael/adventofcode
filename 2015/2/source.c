#include <stdio.h>

void part1(FILE *fp)
{
    int l, h, w, total = 0;
    char buf[32] = {0}, *p = NULL;

    while ((p = fgets(&buf[0], 32, fp)) != NULL) {
        sscanf(&buf[0], "%dx%dx%d", &l, &w, &h);
        total += (2 * l * w) + (2 * w * h) + (2 * h * l);
        if (l * w > w * h) {
            if (w * h > h * l)
                total += h * l;
            else
                total += w * h;
        } else if (l * w > h * l) {
            total += h * l;
        } else
            total += l * w;
    }

    printf("%d\n", total);
}

void part2(FILE *fp)
{
    int l, h, w, total = 0;
    char buf[32] = {0}, *p = NULL;

    while ((p = fgets(&buf[0], 32, fp)) != NULL) {
        sscanf(&buf[0], "%dx%dx%d", &l, &w, &h);
        total += 2 * (l + w > w + h ? w + h > l + h ? l + h : w + h :
                      l + w > l + h ? l + h : l + w);
        total += l * w * h;
    }

    printf("%d\n", total);
}

int main(int argc, char **argv)
{
    FILE *fp = fopen(argv[2], "r");

    if (argv[1][0] == '1')
        part1(fp);
    else
        part2(fp);

    return 0;
}
