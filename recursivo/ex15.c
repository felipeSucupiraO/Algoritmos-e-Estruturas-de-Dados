#include <stdio.h>
#include <stdlib.h>

void printarNaturais(int n) {
    if (n == 1) {
        printf("1");
    } else {
        printarNaturais(n-1);
        printf(" %d", n);
    }
}

int main() {
    int num;
    scanf("%d", &num);
    printarNaturais(num);
    printf("\n");
    
    return 0;
}