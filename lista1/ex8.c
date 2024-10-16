#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ePrimo(unsigned long long int num) {
    if (num == 2) {
        return 1;
    }

    unsigned long long int i = 2;
    while (i < sqrt(num)) {
        if (num % i == 0) {
            return 0;
        }
        i++;
    }
}

int main() {
    int numTestes;
    scanf("%d", &numTestes);

    unsigned long long int num;
    while (numTestes--) {
        scanf("%lld", &num);
        if (ePrimo(num)) {
            printf("primo\n");
        } else {
            printf("composto\n");
        }
    }
    
    return 0;
}