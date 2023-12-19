#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void part1(FILE *fp)
{
    int64_t houses = 1, *pos = NULL;
    int32_t x = 0, y = 0;

    pos = realloc(pos, sizeof(int64_t));
    *pos = 0;

    int c, new, i = 1;
    while ((c = fgetc(fp)) != EOF) {
        i++;
        pos = realloc(pos, i * sizeof(int64_t));

        switch(c) {
        case '^': y++; break;
        case 'v': y--; break;
        case '>': x++; break;
        case '<': x--; break;
        }

        pos[i - 1] = ((int64_t)x << (sizeof(int32_t) * 8)) + (int64_t)y;

        new = 1;
        for (int n = 0; n < i - 1; n++) {
            if (pos[i - 1] == pos[n]) {
                new = 0;
                break;
            }
        }

        if (new)
            houses++;
    }

    printf("%ld\n", houses);
    free(pos);
}

void part2(FILE *fp)
{
    int64_t houses = 1, *pos = NULL;
    int32_t nx = 0, ny = 0, rx = 0, ry = 0;

    pos = realloc(pos, sizeof(int64_t));

    int c, new, i = 1;
    while((c = fgetc(fp)) != EOF) {
        i++;

        if (i & 1) {
            switch(c) {
            case '^': ny++; break;
            case 'v': ny--; break;
            case '>': nx++; break;
            case '<': nx--; break;
            }

            pos = realloc(pos, i * sizeof(int64_t));
            pos[i - 1] = ((uint64_t)nx << (sizeof(uint32_t) * 8)) + (int64_t)ny;

        } else {
            switch(c) {
            case '^': ry++; break;
            case 'v': ry--; break;
            case '>': rx++; break;
            case '<': rx--; break;
            }

            pos = realloc(pos, i * sizeof(int64_t));
            pos[i - 1] = ((uint64_t)rx << (sizeof(uint32_t) * 8)) + (int64_t)ry;
        }

        new = 1;
        for (int n = 0; n < i - 1; n++) {
            if (pos[n] == pos[i - 1]) {
                new = 0;
                break;
            }
        }

        if (new)
            houses++;
    }

    printf("%ld\n", houses);
    free(pos);
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
