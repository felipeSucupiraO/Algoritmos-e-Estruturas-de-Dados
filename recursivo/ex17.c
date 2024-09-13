#include <stdio.h>
#include <stdlib.h>

void printarNumInvertidoRecursivo(char *strNum, int digito, int temNumAEsquerda) {
    int novoTemNumAEsquerda = temNumAEsquerda;
    if (strNum[digito] != '0') {
        novoTemNumAEsquerda = 1;
    }
    if (digito < 2) {
        printarNumInvertidoRecursivo(strNum, digito + 1, novoTemNumAEsquerda);
    }
    if (!(temNumAEsquerda == 1 && strNum[digito] == '0')) {
        printf("%c", strNum[digito]);
    }
}

void printarNumInvertido(char *strNum) {
    printarNumInvertidoRecursivo(strNum, 0, 0);
}

int main() {
    char strNum[3];
    scanf("%[^\n]s", strNum);

    printarNumInvertido(strNum);
    printf("\n");
    
    return 0;
}