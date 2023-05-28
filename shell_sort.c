#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_1 100
#define SIZE_2 1000
#define SIZE_3 10000

void preencherVetorAleatorio(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 1000;
    }
}

void preencherVetorOrdenadoAscendente(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = i + 1;
    }
}

void preencherVetorOrdenadoDescendente(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - i;
    }
}

// Função auxiliar para trocar dois elementos
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//--------------------------------------------------------------------------------
// Implementação do Insertion Sort
void insertionSort(int vetor[], int tamanho, int *comparacoes, int *trocas) {
    for (int i = 1; i < tamanho; i++) {
        int chave = vetor[i];
        int j = i - 1;
        
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            (*comparacoes)++;
            (*trocas)++;
            j--;
        }
        
        vetor[j + 1] = chave;
        (*trocas)++;
    }
}

//--------------------------------------------------------------------------------
// Implementação do Selection Sort
void selectionSort(int vetor[], int tamanho, int *comparacoes, int *trocas) {
    for (int i = 0; i < tamanho - 1; i++) {
        int indiceMinimo = i;
        
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[indiceMinimo]) {
                indiceMinimo = j;
            }
            (*comparacoes)++;
        }
        
        trocar(&vetor[i], &vetor[indiceMinimo]);
        (*trocas)++;
    }
}

//--------------------------------------------------------------------------------
// Implementação do Bubble Sort
void bubbleSort(int vetor[], int tamanho, int *comparacoes, int *trocas) {
    for (int i = 0; i < tamanho - 1; i++) {
        int trocou = 0;
        
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                trocar(&vetor[j], &vetor[j + 1]);
                (*trocas)++;
                trocou = 1;
            }
            (*comparacoes)++;
        }
        
        if (!trocou) {
            break;
        }
    }
}

//--------------------------------------------------------------------------------
// Implementação do Merge Sort
void merge(int vetor[], int inicio, int meio, int fim, int *comparacoes, int *trocas) {
    int tamanho1 = meio - inicio + 1;
    int tamanho2 = fim - meio;
    
    int vetorEsquerdo[tamanho1], vetorDireito[tamanho2];
    
    for (int i = 0; i < tamanho1; i++) {
        vetorEsquerdo[i] = vetor[inicio + i];
    }
    for (int j = 0; j < tamanho2; j++) {
        vetorDireito[j] = vetor[meio + 1 + j];
    }
    
    int i = 0, j = 0, k = inicio;
    
    while (i < tamanho1 && j < tamanho2) {
        if (vetorEsquerdo[i] <= vetorDireito[j]) {
            vetor[k] = vetorEsquerdo[i];
            i++;
        } else {
            vetor[k] = vetorDireito[j];
            j++;
        }
        (*comparacoes)++;
        (*trocas)++;
        k++;
    }
    
    while (i < tamanho1) {
        vetor[k] = vetorEsquerdo[i];
        i++;
        k++;
        (*trocas)++;
    }
    
    while (j < tamanho2) {
        vetor[k] = vetorDireito[j];
        j++;
        k++;
        (*trocas)++;
    }
}
void mergeSort(int vetor[], int inicio, int fim, int *comparacoes, int *trocas) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        
        mergeSort(vetor, inicio, meio, comparacoes, trocas);
        mergeSort(vetor, meio + 1, fim, comparacoes, trocas);
        
        merge(vetor, inicio, meio, fim, comparacoes, trocas);
    }
}

//--------------------------------------------------------------------------------
// Implementação do Quick Sort
int particionar(int vetor[], int inicio, int fim, int *comparacoes, int *trocas) {
    int pivo = vetor[fim];
    int i = inicio - 1;
    
    for (int j = inicio; j <= fim - 1; j++) {
        if (vetor[j] <= pivo) {
            i++;
            trocar(&vetor[i], &vetor[j]);
            (*trocas)++;
        }
        (*comparacoes)++;
    }
    
    trocar(&vetor[i + 1], &vetor[fim]);
    (*trocas)++;
    
    return i + 1;
}
void quickSort(int vetor[], int inicio, int fim, int *comparacoes, int *trocas) {
    if (inicio < fim) {
        int pivo = particionar(vetor, inicio, fim, comparacoes, trocas);
        
        quickSort(vetor, inicio, pivo - 1, comparacoes, trocas);
        quickSort(vetor, pivo + 1, fim, comparacoes, trocas);
    }
}

//--------------------------------------------------------------------------------
// Implementação do Shell Sort
void shellSort(int vetor[], int tamanho, int *comparacoes, int *trocas) {
    for (int gap = tamanho / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < tamanho; i++) {
            int chave = vetor[i];
            int j = i;
            
            while (j >= gap && vetor[j - gap] > chave) {
                vetor[j] = vetor[j - gap];
                (*comparacoes)++;
                (*trocas)++;
                j -= gap;
            }
            
            vetor[j] = chave;
            (*trocas)++;
        }
    }
}

//--------------------------------------------------------------------------------
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int VetorInsertion1_1[SIZE_1];
    int VetorInsertion1_2[SIZE_1];
    int VetorInsertion1_3[SIZE_1];
    int VetorInsertion2_1[SIZE_2];
    int VetorInsertion2_2[SIZE_2];
    int VetorInsertion2_3[SIZE_2];
    int VetorInsertion3_1[SIZE_3];
    int VetorInsertion3_2[SIZE_3];
    int VetorInsertion3_3[SIZE_3];

    // tamanho 100
    preencherVetorAleatorio(VetorInsertion1_1, SIZE_1);
    preencherVetorOrdenadoAscendente(VetorInsertion1_2, SIZE_1);
    preencherVetorOrdenadoDescendente(VetorInsertion1_3, SIZE_1);

    // tamanho 1000
    preencherVetorAleatorio(VetorInsertion2_1, SIZE_2);
    preencherVetorOrdenadoAscendente(VetorInsertion2_2, SIZE_2);
    preencherVetorOrdenadoDescendente(VetorInsertion2_3, SIZE_2);

    // tamanho 10000
    preencherVetorAleatorio(VetorInsertion3_1, SIZE_3);
    preencherVetorOrdenadoAscendente(VetorInsertion3_2, SIZE_3);
    preencherVetorOrdenadoDescendente(VetorInsertion3_3, SIZE_3);
    int comparacoesInsertion = 0, trocasInsertion = 0;


    //TAMANHO 100
    comparacoesInsertion = 0, trocasInsertion = 0;
    clock_t inicio1, fim1;
    inicio1 = clock();
    insertionSort(VetorInsertion1_1, SIZE_1, &comparacoesInsertion, &trocasInsertion);
    fim1 = clock();
    double tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Insertion Sort (tamanho %d):\n", SIZE_1);
    printf("Comparacoes: %d\n", comparacoesInsertion);
    printf("Trocas: %d\n", trocasInsertion);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");
    
    comparacoesInsertion = 0, trocasInsertion = 0;
    clock_t inicio2, fim2;
    inicio2 = clock();
    insertionSort(VetorInsertion1_2, SIZE_1, &comparacoesInsertion, &trocasInsertion);
    fim2 = clock();
    double tempo2 = (double)(fim2 - inicio2) / CLOCKS_PER_SEC;
    printf("Insertion Sort (tamanho %d):\n", SIZE_1);
    printf("Comparacoes: %d\n", comparacoesInsertion);
    printf("Trocas: %d\n", trocasInsertion);
    printf("Tempo: %f segundos\n", tempo2);
    printf("\n");

    comparacoesInsertion = 0, trocasInsertion = 0;
    clock_t inicio3, fim3;
    inicio3 = clock();
    insertionSort(VetorInsertion1_3, SIZE_1, &comparacoesInsertion, &trocasInsertion);
    fim3 = clock();
    double tempo3 = (double)(fim3 - inicio3) / CLOCKS_PER_SEC;
    printf("Insertion Sort (tamanho %d):\n", SIZE_1);
    printf("Comparacoes: %d\n", comparacoesInsertion);
    printf("Trocas: %d\n", trocasInsertion);
    printf("Tempo: %f segundos\n", tempo3);
    printf("\n");



    //TAMANHO 1000
    comparacoesInsertion = 0, trocasInsertion = 0;
    clock_t inicio4, fim4;
    inicio4 = clock();
    insertionSort(VetorInsertion2_1, SIZE_2, &comparacoesInsertion, &trocasInsertion);
    fim4 = clock();
    double tempo4 = (double)(fim4 - inicio4) / CLOCKS_PER_SEC;
    printf("Insertion Sort (tamanho %d):\n", SIZE_2);
    printf("Comparacoes: %d\n", comparacoesInsertion);
    printf("Trocas: %d\n", trocasInsertion);
    printf("Tempo: %f segundos\n", tempo4);
    printf("\n");
    
    comparacoesInsertion = 0, trocasInsertion = 0;
    clock_t inicio5, fim5;
    inicio5 = clock();
    insertionSort(VetorInsertion2_2, SIZE_2, &comparacoesInsertion, &trocasInsertion);
    fim5 = clock();
    double tempo5 = (double)(fim5 - inicio5) / CLOCKS_PER_SEC;
    printf("Insertion Sort (tamanho %d):\n", SIZE_2);
    printf("Comparacoes: %d\n", comparacoesInsertion);
    printf("Trocas: %d\n", trocasInsertion);
    printf("Tempo: %f segundos\n", tempo5);
    printf("\n");

    comparacoesInsertion = 0, trocasInsertion = 0;
    clock_t inicio6, fim6;
    inicio6 = clock();
    insertionSort(VetorInsertion2_3, SIZE_2, &comparacoesInsertion, &trocasInsertion);
    fim6 = clock();
    double tempo6 = (double)(fim6 - inicio6) / CLOCKS_PER_SEC;
    printf("Insertion Sort (tamanho %d):\n", SIZE_2);
    printf("Comparacoes: %d\n", comparacoesInsertion);
    printf("Trocas: %d\n", trocasInsertion);
    printf("Tempo: %f segundos\n", tempo6);
    printf("\n");



    //TAMANHO 10000
    comparacoesInsertion = 0, trocasInsertion = 0;
    clock_t inicio7, fim7;
    inicio7 = clock();
    insertionSort(VetorInsertion3_1, SIZE_3, &comparacoesInsertion, &trocasInsertion);
    fim7 = clock();
    double tempo7 = (double)(fim7 - inicio7) / CLOCKS_PER_SEC;
    printf("Insertion Sort (tamanho %d):\n", SIZE_3);
    printf("Comparacoes: %d\n", comparacoesInsertion);
    printf("Trocas: %d\n", trocasInsertion);
    printf("Tempo: %f segundos\n", tempo7);
    printf("\n");
    
    comparacoesInsertion = 0, trocasInsertion = 0;
    clock_t inicio8, fim8;
    inicio8 = clock();
    insertionSort(VetorInsertion3_2, SIZE_3, &comparacoesInsertion, &trocasInsertion);
    fim8 = clock();
    double tempo8 = (double)(fim8 - inicio8) / CLOCKS_PER_SEC;
    printf("Insertion Sort (tamanho %d):\n", SIZE_3);
    printf("Comparacoes: %d\n", comparacoesInsertion);
    printf("Trocas: %d\n", trocasInsertion);
    printf("Tempo: %f segundos\n", tempo8);
    printf("\n");

    comparacoesInsertion = 0, trocasInsertion = 0;
    clock_t inicio9, fim9;
    inicio9 = clock();
    insertionSort(VetorInsertion3_3, SIZE_3, &comparacoesInsertion, &trocasInsertion);
    fim9 = clock();
    double tempo9 = (double)(fim9 - inicio9) / CLOCKS_PER_SEC;
    printf("Insertion Sort (tamanho %d):\n", SIZE_3);
    printf("Comparacoes: %d\n", comparacoesInsertion);
    printf("Trocas: %d\n", trocasInsertion);
    printf("Tempo: %f segundos\n", tempo9);
    printf("\n");

    return 0;
}
