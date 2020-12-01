#include <stdio.h>
#include <malloc.h>

int main() {

    size_t len = 200;
    int *buf = malloc(len * sizeof(int));

    size_t i = 0;

    while(fscanf(stdin,"%d", buf+i) == 1) {
        printf("%d\n", buf[i]);
        i++;
    }

    for (int k = 0; k < i; k++)
        for (int j = k + 1; j < i; j++)
            if (buf[k] + buf[j] == 2020)
                printf("%d", buf[k] * buf[j]);

    free(buf);
    buf = NULL;

    return 0;
}