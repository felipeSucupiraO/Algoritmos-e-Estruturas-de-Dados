#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char *alocar(int tamanho) {
    char *vetor = NULL;
    while (vetor == NULL) {
        vetor = (char*)malloc(tamanho * sizeof(char));
    }

    return vetor;
}

int toInt(char caracter) {
    return caracter - '0';
}

char toChar(int num) {
    return num + '0';
}

char *toString(char caracter) {
    char *string = alocar(3);
    string[0] = caracter;
    string[1] = '\0';
    return string;
}

int digito(int num, int digito) {
    return floor((double)num/pow(10, digito)) - (floor(num/pow(10, digito+1)) * 10);
}

char *somarNums(char *num1, char *num2) {
    int tamanho1 = strlen(num1);
    int tamanho2 = strlen(num2);
    int numAtual;
    int resto = 0;
    char *resposta = alocar(200);
    resposta[0] = '\0';
    char *digitoAdicionado;

    int i = tamanho1 - 1;
    int j = tamanho2 - 1;
    while (i >= 0 && j >= 0) {
        numAtual = toInt(num1[i]) + toInt(num2[j]);
        numAtual += resto;

        digitoAdicionado = toString(toChar(digito(numAtual, 0)));
        strcpy(resposta, strcat(digitoAdicionado, resposta));
        resto = digito(numAtual, 1);
        free(digitoAdicionado);

        i--;
        j--;
    }

    while (i >= 0) {
        numAtual = toInt(num1[i]);
        numAtual += resto;

        digitoAdicionado = toString(toChar(digito(numAtual, 0)));
        strcpy(resposta, strcat(digitoAdicionado, resposta));
        resto = digito(numAtual, 1);
        free(digitoAdicionado);

        i--;
    }
    while (j >= 0) {
        numAtual = toInt(num2[j]);
        numAtual += resto;

        digitoAdicionado = toString(toChar(digito(numAtual, 0)));
        strcpy(resposta, strcat(digitoAdicionado, resposta));
        resto = digito(numAtual, 1);
        free(digitoAdicionado);

        j--;
    }

    while (resto != 0) {
        numAtual = resto;

        digitoAdicionado = toString(toChar(digito(numAtual, 0)));
        strcpy(resposta, strcat(digitoAdicionado, resposta));
        resto = digito(numAtual, 1);
        free(digitoAdicionado);
    }

    return resposta;
}

char *multiplicarNums(char *num1, char *num2) {
    int tamanho1 = strlen(num1);
    int tamanho2 = strlen(num2);
    char *resposta = alocar(100);
    resposta[1] = '\0';
    resposta[0] = '0';
    char *numSomadoAtual = alocar(100);
    int resto = 0;
    int numAtual;
    char *digitoAdicionado;

    int i, j, k;
    for (i = tamanho1 - 1; i >= 0; i--) {
        numSomadoAtual[0] = '\0';
        
        for (j = tamanho2 - 1; j >= 0; j--) {
            numAtual = toInt(num1[i]) * toInt(num2[j]);
            numAtual += resto;

            digitoAdicionado = toString(toChar(digito(numAtual, 0)));
            strcpy(numSomadoAtual, strcat(digitoAdicionado, numSomadoAtual));
            resto = digito(numAtual, 1);
            free(digitoAdicionado);
        }
        k = tamanho1 - 1 - i;
        while (k > 0) {
            strcat(numSomadoAtual, "0");
            k--;
        }

        resposta = somarNums(resposta, numSomadoAtual);

        free(numSomadoAtual);
    }

    return resposta;
}

int main() {
    char num1[20];
    char num2[20];
    strcpy(num1, "12");
    strcpy(num2, "3");

    char *resposta = multiplicarNums(num1, num2);

    printf("%s\n", resposta);

    free(resposta);

    return 0;
}