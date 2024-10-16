#include <stdio.h>
#include <stdlib.h>

int* alocarVetor(int tamanho) {
    int *vetor = NULL;
    while (vetor == NULL) {
        vetor = (int*)malloc(tamanho * sizeof(int));
    }
    return vetor;
}

int main() {
    int numRotulos, numTipos;
    scanf("%d %d", &numRotulos, &numTipos);
    
    int *_rotulos = alocarVetor(numTipos);
    int i;
    for (i = 0; i < numTipos; i++) {
        _rotulos[i] = 0;
    }

    int numAtual;
    for (i = 0; i < numRotulos; i++) {
        scanf("%d", &numAtual);
        _rotulos[numAtual - 1]++;
    }
    
    int menorQuantidadeRotulos = numRotulos;
    for (i = 0; i < numTipos; i++) {
        if (_rotulos[i] < numRotulos) {
            menorQuantidadeRotulos = _rotulos[i];
        }
    }

    printf("%d\n", menorQuantidadeRotulos);
    free(_rotulos);

    return 0;
}