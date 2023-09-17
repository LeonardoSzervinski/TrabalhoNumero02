#include <stdio.h>
#include <string.h>

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char **arr, int low, int high, int *trocas, int *comparacoes) {
    char *pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        (*comparacoes)++;
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            (*trocas)++;
            swap(&arr[i], &arr[j]);
        }
    }
    (*trocas)++;
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
