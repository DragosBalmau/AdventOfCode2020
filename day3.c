/*
 *
 * https://adventofcode.com/2020/day/3
 *
 * */

#include <stdio.h>
#include <string.h>

int main() {

    int down[5] = {1, 1, 1, 1, 2};
    int right[5] = {1, 3, 5, 7, 1};
    long long int total = 1;

    for (int i = 0; i < 5; i++) {
        char row[100];
        FILE *f = fopen("date.in", "r");
        int x = 0;
        int nr = 0, skippedRows = 0;
        while (fscanf(f, "%s", row) != EOF) {
            if (skippedRows == 0) {
                if (down[i] > 1)
                    skippedRows = down[i] - 1;
                if (row[x] == '#') {
                    nr++;
                    row[x] = 'X';
                } else
                    row[x] = 'O';
                x += right[i];
                if (x >= strlen(row))
                    x -= strlen(row);
            }
            else
                skippedRows--;

            printf("%s\n", row);
        }
        fclose(f);
        printf("Total %d: %d\n", i+1, nr);
        total *= nr;

    }
    printf("Total: %lld", total);

}
