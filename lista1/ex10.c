#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double PI = 3.14159265;

int arredondar(double num) {
    if (num >= (floor(num) + 0.5)) {
        return ceil(num);
    }
    return floor(num);
}

double areaCirculo(double raio) {
    return PI * pow(raio, 2);
}

double areaTriangulo(double lado1, double lado2, double lado3) {
    double semiperimetro = (lado1 + lado2 + lado3) / 2;
    return sqrt(semiperimetro*(semiperimetro - lado1)*(semiperimetro - lado2)*(semiperimetro - lado3));
}

double areaElipse(double raizGrande, double raizPequena) {
    return PI * raizGrande * raizPequena;
}

double areaTrapezio(double baseMaior, double baseMenor, double altura) {
    return ((baseMaior + baseMenor)*altura) / 2;
}

int main() {
    int numTestes;
    scanf("%d", &numTestes);

    char figura;
    int parm1, parm2, parm3;
    while (numTestes--) {
        scanf(" %c", &figura);

        if (figura == 'C') {
            scanf("%d", &parm1);
            printf("%d\n", arredondar(areaCirculo(parm1)));
        } else if (figura == 'E') {
            scanf("%d %d", &parm1, &parm2);
            printf("%d\n", arredondar(areaElipse(parm1, parm2)));
        } else if (figura == 'T') {
            scanf("%d %d %d", &parm1, &parm2, &parm3);
            printf("%d\n", arredondar(areaTriangulo(parm1, parm2, parm3)));
        } else if (figura == 'Z') {
            scanf("%d %d %d", &parm1, &parm2, &parm3);
            printf("%d\n", arredondar(areaTrapezio(parm1, parm2, parm3)));
        }
    }
    
    return 0;
}