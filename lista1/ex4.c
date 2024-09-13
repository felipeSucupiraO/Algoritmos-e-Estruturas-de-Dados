#include <stdio.h>
#include <stdlib.h>

#include <math.h>

int digito(int num, int digito) {
    return floor((double)num/pow(10, digito)) - (floor(num/pow(10, digito+1)) * 10);
}

int numDigitos(int num) {
    return floor(log10(num)) + 1;
}

int main() {
    int numTestes;
    scanf("%d", &numTestes);
    
    int numAtual, resposta, ePrimeiroDigito = 1;
    while (numTestes--) {
        resposta = 1;
        scanf("%d", &numAtual);
        int numDigitosAtual = numDigitos(numAtual);

        int i;
        for (i = 0; i < ceil((double)numDigitosAtual); i++) {
            if (digito(numAtual, i) != digito(numAtual, numDigitosAtual - i - 1)) {
                resposta = 0;
                break;
            }
        }

        if (ePrimeiroDigito) {
            ePrimeiroDigito = 0;
        } else {
            printf(" ");
        }
        if (resposta == 1) {
            printf("yes");
        } else {
            printf("no");
        }
    }
    return 0;
}