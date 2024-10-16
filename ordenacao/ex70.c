#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {
    int numQuestoes;
    char nome[21];
} typedef Aluno;

int eLexicograficamenteMenor(char *nome1, char *nome2) {
    int i = 0;
    while (i < strlen(nome1) && i < strlen(nome2)) {
        if (nome1[i] < nome2[i]) {
            return 1;
        } else if (nome1[i] > nome2[i]) {
            return 0;
        }
        i++;
    }
    if (i < strlen(nome1)) {
        return 1;
    } else {
        return 0;
    }
}

void copiarAluno(Aluno *aluno1, Aluno *aluno2) {
    strcpy(aluno1->nome, aluno2->nome);
    aluno1->numQuestoes = aluno2->numQuestoes;
}

Aluno *alocarVetor(int tamanho) {
    Aluno *vetor = NULL;
    while (vetor == NULL) {
        vetor = (Aluno*)malloc(tamanho * sizeof(Aluno));
    }
    return vetor;
}

void insertionSort(Aluno *vetor, int tamanhoVetor) {
    int i, j = 1;
    int auxiliar;
    char stringAuxiliar[21];

    while (j < tamanhoVetor) {
        i = j - 1;
        auxiliar = vetor[j].numQuestoes;
        strcpy(stringAuxiliar, vetor[j].nome);
        while (i >= 0 && vetor[i].numQuestoes <= auxiliar) {
            if (vetor[i].numQuestoes == auxiliar && eLexicograficamenteMenor(vetor[i].nome, stringAuxiliar)) {
                break;
            }
            copiarAluno(&vetor[i + 1], &vetor[i]);
            i--;
        }

        strcpy(vetor[i + 1].nome, stringAuxiliar);
        vetor[i + 1].numQuestoes = auxiliar;
        j++;
    }
}

int main() {
    int numAlunos;
    scanf("%d", &numAlunos);

    Aluno *vetor = alocarVetor(numAlunos);
    
    int i;
    for (i = 0; i < numAlunos; i++) {
        scanf(" %s", vetor[i].nome);
        scanf("%d", &vetor[i].numQuestoes);
    }

    insertionSort(vetor, numAlunos);

    for (i = 0; i < numAlunos; i++) {
        printf("%s %d ", vetor[i].nome, vetor[i].numQuestoes);
        if (i != numAlunos - 1) {
            printf("\n");
        }
    }
    printf("#reprovado(a)\n");

    free(vetor);

    return 0;
}