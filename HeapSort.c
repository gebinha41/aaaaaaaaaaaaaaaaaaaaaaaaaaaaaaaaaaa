#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para garantir que a propriedade de heap seja mantida
void heapify(double* arr, int heapSize, int i) {
    int maior = i;
    int noEsquerda = 2 * i + 1;
    int noDireita = 2 * i + 2;

    // Verificar se o nó esquerdo existe e é maior que o nó atual
    if (noEsquerda < heapSize && arr[noEsquerda] > arr[maior]) {
        maior = noEsquerda;
    }

    // Verificar se o nó direito existe e é maior que o nó atual
    if (noDireita < heapSize && arr[noDireita] > arr[maior]) {
        maior = noDireita;
    }

    // Se o maior nó não for o nó atual, trocar e continuar a heapificação
    if (maior != i) {
        double troca = arr[i];
        arr[i] = arr[maior];
        arr[maior] = troca;

        heapify(arr, heapSize, maior);
    }
}

// Função principal do Heap Sort
void heapSort(double* arr, int tamanho) {
    // Construir o heap máximo
    for (int i = tamanho / 2 - 1; i >= 0; i--) {
        heapify(arr, tamanho, i);
    }

    // Extrair elementos do heap um por um
    for (int i = tamanho - 1; i >= 0; i--) {
        // Mover o elemento atual para o final
        double temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Chamar heapify no heap reduzido
        heapify(arr, i, 0);
    }
}

// Função para calcular o tempo de execução
long calcularTempoAlgoritmo(double* arr, int tamanho) {
    clock_t tempoInicial = clock();

    heapSort(arr, tamanho);

    return (long)(clock() - tempoInicial);
}

// Função para exibir o vetor
void exibirVetor(double* arr, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Exemplo de vetor para ordenar
    double arr[] = {12.5, 3.2, 5.1, 7.6, 9.8, 1.3, 4.4, 6.7};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    printf("Vetor original: \n");
    exibirVetor(arr, tamanho);

    // Calcular tempo de execução
    long tempoDecorrido = calcularTempoAlgoritmo(arr, tamanho);

    printf("Vetor ordenado: \n");
    exibirVetor(arr, tamanho);

    printf("Tempo de execução: %ld milissegundos\n", tempoDecorrido);

    return 0;
}
