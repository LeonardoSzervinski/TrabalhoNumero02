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

    quicksort(arr, 0, n - 1, &trocas, &comparacoes);

    printf("Numero de trocas: %d\n", trocas);
    printf("Numero de comparacoes: %d\n", comparacoes);

    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("(%d) %s\n", i + 1, arr[i]);
    }

    char *mediana;
    if (n % 2 == 0) {
        mediana = arr[n / 2 - 1];
    } else {
        mediana = arr[n / 2];
    }
    printf("Mediana: %s\n", mediana);

    FILE *saida = fopen("saida.txt", "w");
    if (saida == NULL) {
        printf("Erro ao criar o arquivo de saída.");
        return 1;
    }
    fprintf(saida, "Número de trocas: %d\n", trocas);
    fprintf(saida, "Número de comparações: %d\n", comparacoes);
    fprintf(saida, "Vetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        fprintf(saida, "(%d) %s\n", i + 1, arr[i]);
    }
    fprintf(saida, "Mediana: %s\n", mediana);
    fclose(saida);

    return 0;
}