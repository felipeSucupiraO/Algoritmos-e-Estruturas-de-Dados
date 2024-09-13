#include <stdio.h>
#include <stdlib.h>

char algarismoBase4(int algarismo) {
    switch (algarismo) {
        case 0: return 'A';
            break;
        case 1: return 'C';
            break;
        case 2: return 'G';
            break;
        case 3: return 'T';
            break;
        default: return;
            break;
    }
}

void printarConversaoBase4(int numAtual) {
    if (numAtual < 4) {
        printf("%c", algarismoBase4(numAtual));
    } else {
        printarConversaoBase4(numAtual/4);
        printf("%c", algarismoBase4(numAtual%4));
    }
}


int main() {
    int numCasos;
    scanf("%d", &numCasos);

    int numBase10;
    while (numCasos--) {
        scanf("%d", &numBase10);

        printarConversaoBase4(numBase10);
        printf("\n");
    }
    
    
    return 0;
}