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

void quicksort(char **arr, int low, int high, int *trocas, int *comparacoes) {
    if (low < high) {
        int pi = partition(arr, low, high, trocas, comparacoes);
        quicksort(arr, low, pi - 1, trocas, comparacoes);
        quicksort(arr, pi + 1, high, trocas, comparacoes);
    }
}

int main() {
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi",
        "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"
    };
    int trocas = 0, comparacoes = 0;

    int n = sizeof(arr) / sizeof(arr[0]);

    