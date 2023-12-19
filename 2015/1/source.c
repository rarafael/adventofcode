#include <stdio.h>

void part1(FILE *fp)
{
    int floor = 0, c;

    while ((c = fgetc(fp)) != EOF) {
        if (c - 40)
            floor--;
        else
            floor++;
    }

    printf("%d\n", floor);
}

void part2(FILE *fp)
{
    int floor = 0, c, i = 0;

    while ((c = fgetc(fp)) != EOF) {
        i++;
        if (c - 40)
            floor--;
        else
            floor++;
        if (floor < 0) {
            printf("%d\n", i);
            return;
        }
    }
}

int main(int argc, char **argv)
{
    FILE *fp = fopen(argv[2], "r");

    if (argv[1][0] == '1')
        part1(fp);
    else
        part2(fp);

    fclose(fp);
    return 0;
}
