#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para intercambiar as duas metades
void intercalar(double* v, double* w, int ini, int meio, int fim) {
    // Copiar o vetor original para o vetor auxiliar
    for (int k = ini; k <= fim; k++) {
        w[k] = v[k];
    }

    int i = ini;
    int j = meio + 1;

    // Realizar a intercalação
    for (int k = ini; k <= fim; k++) {
        if (i > meio) {
            v[k] = w[j++];
        } else if (j > fim) {
            v[k] = w[i++];
        } else if (w[i] < w[j]) {
            v[k] = w[i++];
        } else {
            v[k] = w[j++];
        }
    }
}

// Função principal do Merge Sort
void mergeSort(double* v, double* w, int ini, int fim) {
    if (ini < fim) {
        int meio = (ini + fim) / 2;
        mergeSort(v, w, ini, meio);
        mergeSort(v, w, meio + 1, fim);
        intercalar(v, w, ini, meio, fim);
    }
}

// Função para calcular o tempo de execução
long calcularTempoAlgoritmo(double* v, int tamanho) {
    clock_t tempoInicial = clock();
    
    // Vetor auxiliar
    double* w = (double*)malloc(tamanho * sizeof(double));

    mergeSort(v, w, 0, tamanho - 1);

    free(w); // Liberar memória alocada para o vetor auxiliar

    return (long)(clock() - tempoInicial);
}

// Função para exibir o vetor
void exibirVetor(double* v, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%f ", v[i]);
    }
    printf("\n");
}

int main() {
    // Exemplo de vetor para ordenar
    double v[] = {12.5, 3.2, 5.1, 7.6, 9.8, 1.3, 4.4, 6.7};
    int tamanho = sizeof(v) / sizeof(v[0]);

    printf("Vetor original: \n");
    exibirVetor(v, tamanho);

    // Calcular tempo de execução
    long tempoDecorrido = calcularTempoAlgoritmo(v, tamanho);
    printf("Vetor ordenado: \n");
    exibirVetor(v, tamanho);
    
    printf("Tempo de execução: %ld milissegundos\n", tempoDecorrido);

    return 0;
}
