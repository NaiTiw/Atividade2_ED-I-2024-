#include <stdio.h>
#include <locale.h>
#define MAX_SIZE 20

typedef struct {
    int elementos[MAX_SIZE];
    int tamanho;
} Conjunto;

Conjunto criarConjuntoVazio() {
    Conjunto novoConjunto;
    novoConjunto.tamanho = 0;
    return novoConjunto;
}

void lerConjunto(Conjunto *conjunto) {
    printf("Digite o número de elementos no conjunto: ");
    scanf("%d", &conjunto->tamanho);

    printf("Digite os elementos do conjunto:\n");
    for (int i = 0; i < conjunto->tamanho; i++) {
        scanf("%d", &conjunto->elementos[i]);
    }
}

Conjunto unirConjuntos(Conjunto conjunto1, Conjunto conjunto2) {
    Conjunto conjuntoResultado = criarConjuntoVazio();

    for (int i = 0; i < conjunto1.tamanho; i++) {
        conjuntoResultado.elementos[i] = conjunto1.elementos[i];
        conjuntoResultado.tamanho++;
    }

    for (int i = 0; i < conjunto2.tamanho; i++) {
        int encontrado = 0;
        for (int j = 0; j < conjuntoResultado.tamanho; j++) {
            if (conjunto2.elementos[i] == conjuntoResultado.elementos[j]) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado && conjuntoResultado.tamanho < MAX_SIZE) {
            conjuntoResultado.elementos[conjuntoResultado.tamanho++] = conjunto2.elementos[i];
        }
    }

    return conjuntoResultado;
}

Conjunto intersecaoConjuntos(Conjunto conjunto1, Conjunto conjunto2) {
    Conjunto conjuntoResultado = criarConjuntoVazio();

    for (int i = 0; i < conjunto1.tamanho; i++) {
        for (int j = 0; j < conjunto2.tamanho; j++) {
            if (conjunto1.elementos[i] == conjunto2.elementos[j]) {
                conjuntoResultado.elementos[conjuntoResultado.tamanho++] = conjunto1.elementos[i];
                break;
            }
        }
    }

    return conjuntoResultado;
}

void imprimirConjunto(Conjunto conjunto) {
    printf("{ ");
    for (int i = 0; i < conjunto.tamanho; i++) {
        printf("%d", conjunto.elementos[i]);
        if (i < conjunto.tamanho - 1) {
            printf(", ");
        }
    }
    printf(" }\n");
}

int main() {

    setlocale(LC_ALL, "PORTUGUESE");

    Conjunto conjunto1, conjunto2, conjuntoResultado;

    printf("Digite o primeiro conjunto:\n");
    conjunto1 = criarConjuntoVazio();
    lerConjunto(&conjunto1);

    printf("Digite o segundo conjunto:\n");
    conjunto2 = criarConjuntoVazio();
    lerConjunto(&conjunto2);

    printf("União dos conjuntos: ");
    conjuntoResultado = unirConjuntos(conjunto1, conjunto2);
    imprimirConjunto(conjuntoResultado);

    printf("Interseção dos conjuntos: ");
    conjuntoResultado = intersecaoConjuntos(conjunto1, conjunto2);
    imprimirConjunto(conjuntoResultado);

    return 0;
}
