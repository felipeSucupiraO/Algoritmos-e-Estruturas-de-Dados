#include <stdio.h>
#include <stdlib.h>

int fibonnaci(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    
    return fibonnaci(n-1) + fibonnaci(n-2);
}

int main() {
    int n;
    scanf("%d", &n);

    int i;
    for (i = 0; i <= n; i++) {
        printf("%d ", fibonnaci(i));
    }
    
    return 0;
}