#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(double *arr, int esq, int dir);
int particionar(double *arr, int esq, int dir);
void imprimirArray(double *arr, int tamanho);

int main() {
    int tamanho;
    printf("Digite o número de elementos: ");
    scanf("%d", &tamanho);

    // Verifica se o tamanho é válido
    if (tamanho <= 0) {
        fprintf(stderr, "O número de elementos deve ser maior que zero.\n");
        return 1;
    }

    double *numeros = (double *)malloc(tamanho * sizeof(double));
    if (numeros == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return 1;
    }

    // Gerar números aleatórios
    srand((unsigned)time(NULL)); // inicializa o gerador de números aleatórios
    for (int i = 0; i < tamanho; i++) {
        numeros[i] = (double)(rand() % 100); // números entre 0 e 99
    }

    printf("Array original:\n");
    imprimirArray(numeros, tamanho);

    clock_t inicio = clock();
    quickSort(numeros, 0, tamanho - 1);
    clock_t fim = clock();

    printf("Array ordenado:\n");
    imprimirArray(numeros, tamanho);

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC * 1000; // em milissegundos
    printf("Tempo de execução: %.2f ms\n", tempo);

    free(numeros);
    return 0;
}

void quickSort(double *arr, int esq, int dir) {
    if (esq < dir) {
        int indice = particionar(arr, esq, dir);
        quickSort(arr, esq, indice - 1);
        quickSort(arr, indice, dir);
    }
}

int particionar(double *arr, int esq, int dir) {
    double pivot = arr[(esq + dir) / 2];
    int i = esq;
    int j = dir;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) {
            // Troca os elementos
            double tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    return i; // Retorna o índice para a próxima partição
}

void imprimirArray(double *arr, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para particionar o vetor
int particionar(double* arr, int esq, int dir) {
    int i = esq;
    int j = dir;
    double tmp;
    double pivot = arr[(esq + dir) / 2];

    while (i <= j) {
        // Encontrar elemento maior ou igual ao pivô
        while (arr[i] < pivot) {
            i++;
        }

        // Encontrar elemento menor ou igual ao pivô
        while (arr[j] > pivot) {
            j--;
        }

        // Trocar os elementos
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    return i;
}

// Função principal do QuickSort
void quickSort(double* arr, int esq, int dir) {
    if (esq < dir) {
        // Particionar o vetor e obter o índice do pivô
        int indice = particionar(arr, esq, dir);
        
        // Recursão na metade esquerda
        quickSort(arr, esq, indice - 1);
        
        // Recursão na metade direita
        quickSort(arr, indice, dir);
    }
}

// Função para calcular o tempo de execução
long calcularTempoAlgoritmo(double* arr, int tamanho) {
    clock_t tempoInicial = clock();

    quickSort(arr, 0, tamanho - 1);

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
