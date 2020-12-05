/*
 *
 * https://adventofcode.com/2020/day/4
 *
 *
 * */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool byr(char *data) {

    int number = 0;
    printf("byr: ");
    if (strstr(data, "byr:")) {
        char *pointer = strstr(data, "byr:");
        if (pointer[8] == ' ' || pointer[8] == '\0') {
            for (int i = 4; i < 8; i++)
                if (pointer[i] != ' ')
                    number = number * 10 + pointer[i] - '0';
            if (!(number >= 1920 && number <= 2002)) {
                printf("\n");
                return false;
            }
        } else {
            printf("\n");
            return false;
        }
    } else {
        printf("\n");
        return false;
    }
    printf("%d\n", number);
    return true;
}

bool iyr(char *data) {

    int number = 0;
    printf("iyr: ");
    if (strstr(data, "iyr:")) {
        char *pointer = strstr(data, "iyr:");
        if (pointer[8] == ' ' || pointer[8] == '\0') {
            for (int i = 4; i < 8; i++)
                if (pointer[i] != ' ')
                    number = number * 10 + pointer[i] - '0';
            if (!(number >= 2010 && number <= 2020)) {
                printf("\n");
                return false;
            }
        } else {
            printf("\n");
            return false;
        }
    } else {
        printf("\n");
        return false;
    }
    printf("%d\n", number);
    return true;

}

bool eyr(char *data) {

    int number = 0;
    printf("eyr: ");
    if (strstr(data, "eyr:")) {
        char *pointer = strstr(data, "eyr:");
        if (pointer[8] == ' ' || pointer[8] == '\0') {
            for (int i = 4; i < 8; i++)
                if (pointer[i] != ' ')
                    number = number * 10 + pointer[i] - '0';
            if (!(number >= 2020 && number <= 2030)) {
                printf("\n");
                return false;
            }
        } else {
            printf("\n");
            return false;
        }
    } else {
        printf("\n");
        return false;
    }
    printf("%d\n", number);
    return true;

}

bool hgt(char *data) {

    printf("hgt: ");
    if (strstr(data, "hgt:")) {
        char *pointer = strstr(data, "hgt:");
        int number = 0;
        int i = 4;
        while (pointer[i] != ' ' && pointer[i] != '\0') {
            if (pointer[i] == 'c' && pointer[i + 1] == 'm')
                if (number >= 150 && number <= 193) {
                    printf("%dcm\n", number);
                    return true;
                }

            if (pointer[i] == 'i' && pointer[i + 1] == 'n')
                if (number >= 59 && number <= 76) {
                    printf("%din\n", number);
                    return true;
                }
            if (pointer[i] >= '0' && pointer[i] <= '9')
                number = number * 10 + (pointer[i] - '0');
            i++;
        }

    } else {
        printf("\n");
        return false;
    }
    return false;

}

bool hcl(char *data) {

    printf("hcl: ");
    if (strstr(data, "hcl:")) {
        char *pointer = strstr(data, "hcl:");
        if (pointer[4] == '#' && (pointer[11] == ' ' || pointer[11] == '\0')) {
            printf("#");
            for (int i = 5; i < 11; i++) {
                if (!((pointer[i] >= '0' && pointer[i] <= '9') || (pointer[i] >= 'a' && pointer[i] <= 'f'))) {
                    printf("\n");
                    return false;
                } else
                    printf("%c", pointer[i]);
            }
        }
    } else {
        printf("\n");
        return false;
    }
    printf("\n");
    return true;

}

bool ecl(char *data) {

    printf("ecl: ");
    if (strstr(data, "ecl:")) {
        char *pointer = strstr(data, "ecl:");
        if (pointer[7] == ' ' || pointer[7] == '\0') {
            if (strstr(pointer, "amb") ||
                strstr(pointer, "blu") ||
                strstr(pointer, "brn") ||
                strstr(pointer, "gry") ||
                strstr(pointer, "grn") ||
                strstr(pointer, "hzl") ||
                strstr(pointer, "oth")) {
                for (int i = 4; i < 7; i++)
                    printf("%c", pointer[i]);
                printf("\n");
                return true;
            }
        } else {
            printf("\n");
            return false;
        }
    } else {
        printf("\n");
        return false;
    }
    printf("\n");
    return false;

}

bool pid(char *data) {

    printf("pid: ");
    if (strstr(data, "pid:")) {
        char *pointer = strstr(data, "pid:");
        if ((pointer[13] == ' ' || pointer[13] == '\0')) {
            for (int i = 4; i < 13; i++) {
                if (!(pointer[i] >= '0' && pointer[i] <= '9')) {
                    printf("****\n");
                    return false;
                } else
                    printf("%c", pointer[i]);
            }
        } else {
            printf("\n");
            return false;
        }
    } else {
        printf("\n");
        return false;
    }

    printf("\n");
    return true;
}

bool cid(char *data) {

    printf("cid:\n");
    if (strstr(data, "cid:"))
        return true;
    return false;

}

int main() {

    FILE *f = fopen("input.txt", "r");
    char line[150];
    int nr = 0;
    char data[200];
    while (fgets(line, sizeof(line), f)) {

        if (strcmp(line, "\n") != 0) {
            line[strlen(line) - 1] = ' ';
            strcat(data, line);
        } else {
            printf("%s\n\n", data);
            int nrOfDoublePoints = 0;
            for (int i = 0; i < strlen(data); i++)
                if (data[i] == ':')
                    nrOfDoublePoints++;
            if (byr(data) &&
                iyr(data) &&
                eyr(data) &&
                hgt(data) &&
                hcl(data) &&
                ecl(data) &&
                pid(data) &&
                ((nrOfDoublePoints == 7 && !cid(data)) || nrOfDoublePoints == 8))
                nr++;
            printf("nr = %d %d\n-----------\n", nr, nrOfDoublePoints);
            memset(data, 0, sizeof data);
        }
    }
    printf("\nTOTAL: %d", nr);


}
