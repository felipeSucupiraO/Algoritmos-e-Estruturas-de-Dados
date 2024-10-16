#include <stdio.h>
#include <stdlib.h>

int *alocarVetor(int tamanho) {
    int *vetor = NULL;
    while (vetor == NULL) {
        vetor = (int*)malloc(tamanho * sizeof(int));
    }
    return vetor;
}

void insertionSort(int *vetor, int tamanhoVetor) {
    int i, j = 1;
    int auxiliar;

    while (j < tamanhoVetor) {
        i = j - 1;
        auxiliar = vetor[j];
        while (i >= 0 && vetor[i] > auxiliar) {
            vetor[i + 1] = vetor[i];
            i--;
        }

        vetor[i + 1] = auxiliar;
        j++;
    }
}

int main() {
    int numTestes;
    scanf("%d", &numTestes);

    int tamanhoVetor;
    int *vetor;
    while (numTestes--) {
        scanf("%d", &tamanhoVetor);
        vetor = alocarVetor(tamanhoVetor);

        int i;
        for (i = 0; i < tamanhoVetor; i++) {
            scanf("%d", &vetor[i]);
        }

        insertionSort(vetor, tamanhoVetor);

        for (i = 0; i < tamanhoVetor; i++) {
            printf("%d ", vetor[i]);
        }
        printf("\n");

        free(vetor);
        vetor = NULL;
    }
    
    return 0;
}