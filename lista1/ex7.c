#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *alocar(int tamanho) {
    int *vetor = NULL;
    while (vetor == NULL) {
        vetor = (int*)malloc(tamanho * sizeof(int));
    }

    return vetor;
}

int main() {
    int numPedra, numSapos;
    scanf("%d %d", &numPedra, &numSapos);

    int *pedras = alocar(numPedra);
    int i;
    for (i = 0; i < numPedra; i++) {
        pedras[i] = 0;
    }

    int pedraInicial, distanciaPulo, pedraAnalisada;
    for (i = 0; i < numSapos; i++) {
        scanf("%d %d", &pedraInicial, &distanciaPulo);
        pedras[pedraInicial - 1] = 1;

        pedraAnalisada = pedraInicial + distanciaPulo;
        while (pedraAnalisada <= numPedra) {
            pedras[pedraAnalisada - 1] = 1;
            pedraAnalisada += distanciaPulo;
        }
        pedraAnalisada = pedraInicial - distanciaPulo;
        while (pedraAnalisada >= 1) {
            pedras[pedraAnalisada - 1] = 1;
            pedraAnalisada -= distanciaPulo;
        }
    }

    for (i = 0; i < numPedra; i++) {
        printf("%d\n", pedras[i]);
    }

    pedras = NULL;
    free(pedras);
    
    return 0;
}