#include <stdio.h>
#include <stdlib.h>

int *alocarVetor(int tamanho) {
    int *vetor = NULL;
    while (vetor == NULL) {
        vetor = (int*)malloc(tamanho * sizeof(int));
    }
    return vetor;
}

void trocarElementos (int *num1, int *num2) {
    int auxiliar;
    auxiliar = *num1;
    *num1 = *num2;
    *num2 = auxiliar;
}

int bubbleSort(int *vetor, int tamanhoVetor) {
    int i, j, numTrocas = 0;
    for (i = tamanhoVetor - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                trocarElementos(&vetor[j], &vetor[j + 1]);
                numTrocas++;
            }
        }
    }

    return numTrocas;
}

int main() {
    int numTestes;
    scanf("%d", &numTestes);

    int *vetor;
    int tamanhoVetor;
    while (numTestes--) {
        scanf("%d", &tamanhoVetor);
        vetor = alocarVetor(tamanhoVetor);

        int i;
        for (i = 0; i < tamanhoVetor; i++) {
            scanf("%d", &vetor[i]);
        }

        printf("%d\n", bubbleSort(vetor, tamanhoVetor));

        free(vetor);
    }
    
    return 0;
}