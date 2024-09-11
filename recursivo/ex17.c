#include <stdio.h>
#include <stdlib.h>

void printarNumInvertidoRecursivo(char *strNum, int digito) {
    if (digito == 0) {
        printf("%c", strNum[0]);
    } else {
        printf("%c", strNum[digito]);
        printarNumInvertidoRecursivo(strNum, digito - 1);
    }
}

void printarNumInvertido(char *strNum) {
    printarNumInvertidoRecursivo(strNum, 2);
}

int main() {
    char strNum[3];
    scanf("%[^\n]s", strNum);

    printarNumInvertido(strNum);
    printf("\n");
    
    return 0;
}