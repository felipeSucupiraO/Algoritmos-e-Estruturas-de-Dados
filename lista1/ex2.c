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
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    
    int num1Certo = 0, num2Certo = 0;

    int i = 0;
    for (i = 0; i < numDigitos(num1); i++) {
        num1Certo += digito(num1, i) * pow(10, numDigitos(num1) - i - 1);
    }

    i = 0;
    for (int i = 0; i < numDigitos(num2); i++) {
        num2Certo += digito(num2, i) * pow(10, numDigitos(num2) - i - 1);
    }

    if (num1Certo > num2Certo) {
        printf("%d\n", num1Certo);
    } else {
        printf("%d\n", num2Certo);
    }

    return 0;
}