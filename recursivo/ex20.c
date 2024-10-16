#include <stdio.h>
#include <stdlib.h>

int fatorial(int num) {
    if (num == 1 || num == 0) {
        return num;
    }

    if (num % 2 == 0) {
        return fatorial(num - 1);
    } else {
        return num * fatorial(num - 2);
    }
}

int main() {
    int num;
    scanf("%d", &num);
    printf("%d\n", fatorial(num));
    
    return 0;
}