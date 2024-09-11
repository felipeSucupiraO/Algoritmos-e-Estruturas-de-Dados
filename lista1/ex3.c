#include <stdio.h>
#include <stdlib.h>

int main() {
    int limite;
    int num1, num2;
    char operacao;
    scanf("%d", &limite);
    scanf("%d", &num1);
    scanf(" %c", &operacao);
    scanf("%d", &num2);

    int resultado;
    if (operacao == '+') {
        resultado = num1 + num2;
    } else if (operacao == 'x') {
        resultado = num1 * num2;
    }

    if (resultado > limite) {
        printf("overflow\n");
    } else {
        printf("no overflow\n");
    }
    
    return 0;
}