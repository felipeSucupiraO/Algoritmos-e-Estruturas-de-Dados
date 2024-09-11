#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int anoAtual;
    scanf("%d", &anoAtual);

    int anoProxCometa = (1986 + 76*(floor((anoAtual - 1986.0)/76.0))) + 76;

    printf("%d\n", anoProxCometa);
    
    return 0;
}