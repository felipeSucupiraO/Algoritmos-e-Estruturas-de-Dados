#include <stdio.h>
#include <stdlib.h>

void resolverTorreDeHanoi(int numDiscos, char pinoOrigem, char pinoAuxiliar, char pinoDestino) {
    if (numDiscos == 1) {
        printf("(%c,%c)\n", pinoOrigem, pinoDestino);
        return;
    }
    resolverTorreDeHanoi(numDiscos - 1, pinoOrigem, pinoDestino, pinoAuxiliar);
    printf("(%c,%c)\n", pinoOrigem, pinoDestino);
    resolverTorreDeHanoi(numDiscos - 1, pinoAuxiliar, pinoOrigem, pinoDestino);
}

int main() {
    int numDiscos;
    scanf("%d", &numDiscos);
    resolverTorreDeHanoi(numDiscos, 'O', 'A', 'D');
    
    return 0;
}