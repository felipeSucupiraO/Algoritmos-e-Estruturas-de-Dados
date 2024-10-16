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

int particionarDecrescente(int *vetor, int inicial, int final) {
    int pivo = vetor[final];
    int i = inicial - 1;
    int j;
    for (j = inicial; j <= final - 1; j++) {
        if (vetor[j] >= pivo) {
            i++;
            trocarElementos(&vetor[j], &vetor[i]);
        }
    }

    trocarElementos(&vetor[i + 1], &vetor[final]);
    return i + 1;
}

int particionarCrescente(int *vetor, int inicial, int final) {
    int pivo = vetor[final];
    int i = inicial - 1;
    int j;
    for (j = inicial; j <= final - 1; j++) {
        if (vetor[j] <= pivo) {
            i++;
            trocarElementos(&vetor[j], &vetor[i]);
        }
    }

    trocarElementos(&vetor[i + 1], &vetor[final]);
    return i + 1;
}

void quickSortCrescente(int *vetor, int inicial, int final) {
    int meio;
    if (inicial < final) {
        meio = particionarCrescente(vetor, inicial, final);

        quickSortCrescente(vetor, inicial, meio - 1);
        quickSortCrescente(vetor, meio + 1, final);
    }
}

void quickSortDecrescente(int *vetor, int inicial, int final) {
    int meio;
    if (inicial < final) {
        meio = particionarDecrescente(vetor, inicial, final);

        quickSortDecrescente(vetor, inicial, meio - 1);
        quickSortDecrescente(vetor, meio + 1, final);
    }
}

int main() {
    int tamanhoVetor;
    int *vetor;
    scanf("%d", &tamanhoVetor);
    vetor = alocarVetor(tamanhoVetor);

    int i;
    int numPares = 0, numImpares = 0;
    for (i = 0; i < tamanhoVetor; i++) {
        scanf("%d", &vetor[i]);
        if (vetor[i] % 2 == 0) {
            numPares++;
        } else {
            numImpares++;
        }
    }

    int *vetorPares = alocarVetor(numPares);
    int *vetorImpares = alocarVetor(numImpares);
    int j = 0;
    for (i = 0; i < tamanhoVetor; i++) {
        if (vetor[i] % 2 == 0) {
            vetorPares[j] = vetor[i];
            j++;
        }
    }
    j = 0;
    for (i = 0; i < tamanhoVetor; i++) {
        if (vetor[i] % 2 != 0) {
            vetorImpares[j] = vetor[i];
            j++;
        }
    }
    
    quickSortCrescente(vetorPares, 0, numPares - 1);
    quickSortDecrescente(vetorImpares, 0, numImpares - 1);

    for (i = 0; i < numPares; i++) {
        printf("%d ", vetorPares[i]);
    }
    printf("\n");
    for (i = 0; i < numImpares; i++) {
        printf("%d ", vetorImpares[i]);
    }
    printf("\n");

    free(vetor);
    free(vetorImpares);
    free(vetorPares);
    return 0;
}