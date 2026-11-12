#include <stdio.h>

void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                trocar(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int indiceMinimo = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[indiceMinimo]) {
                indiceMinimo = j;
            }
        }
        if (indiceMinimo != i) {
            trocar(&arr[indiceMinimo], &arr[i]);
        }
    }
}

int particionar(int arr[], int baixo, int alto) {
    int pivo = arr[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        if (arr[j] < pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void quickSort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        int indicePivo = particionar(arr, baixo, alto);
        quickSort(arr, baixo, indicePivo - 1);
        quickSort(arr, indicePivo + 1, alto);
    }
}

int main() {
    int dados[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = sizeof(dados) / sizeof(dados[0]);

    printf("Array original:\n");
    imprimirArray(dados, tamanho);

    quickSort(dados, 0, tamanho - 1);

    printf("\nArray ordenado:\n");
    imprimirArray(dados, tamanho);

    return 0;
}