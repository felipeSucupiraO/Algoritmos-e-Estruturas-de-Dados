#include <stdio.h>
#include <stdlib.h>

void printarConversaoBase2(int numAtual) {
    if (numAtual < 2) {
        printf("%c",  '0' + numAtual);
    } else {
        printarConversaoBase2(numAtual/2);
        printf("%c",  '0' + (numAtual%2));
    }
}

int main() {
    int numTestes;
    scanf("%d", &numTestes);

    int numDecimal;
    while (numTestes--) {
        scanf("%d", &numDecimal);
        printarConversaoBase2(numDecimal);
        printf("\n");
    }
    
    return 0;
}