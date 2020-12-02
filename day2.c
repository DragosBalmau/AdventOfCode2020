/*
 *
 * https://adventofcode.com/2020/day/2
 *
 * */

#include <stdio.h>
#include <string.h>

int main() {


    int nrPart1 = 0;
    int nrPart2 = 0;
    int minim, maxim;
    char character;
    char string[200];
    while (scanf("%d-%d %c: %s", &minim, &maxim, &character, string)) {
        int count = 0;
        for (int i = 0; i < strlen(string); i++)
            if (string[i] == character)
                count++;

        if (count <= maxim && count >= minim)
            nrPart1++;

        if ((string[minim - 1] != string[maxim - 1]) && (string[minim - 1] == character || string[maxim - 1] == character))
            nrPart2++;
    }
    printf("%d %d\n", nrPart1, nrPart2);
}
