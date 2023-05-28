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


int main() {
    srand(time(NULL));

    clock_t inicio1, fim1;
    double tempo1;

    int VetorInsertion1_1[SIZE_1];
    int VetorInsertion1_2[SIZE_1];
    int VetorInsertion1_3[SIZE_1];
    int VetorInsertion2_1[SIZE_2];
    int VetorInsertion2_2[SIZE_2];
    int VetorInsertion2_3[SIZE_2];
    int VetorInsertion3_1[SIZE_3];
    int VetorInsertion3_2[SIZE_3];
    int VetorInsertion3_3[SIZE_3];

    int VetorSelection1_1[SIZE_1];
    int VetorSelection1_2[SIZE_1];
    int VetorSelection1_3[SIZE_1];
    int VetorSelection2_1[SIZE_2];
    int VetorSelection2_2[SIZE_2];
    int VetorSelection2_3[SIZE_2];
    int VetorSelection3_1[SIZE_3];
    int VetorSelection3_2[SIZE_3];
    int VetorSelection3_3[SIZE_3];
    
    int VetorBubble1_1[SIZE_1];
    int VetorBubble1_2[SIZE_1];
    int VetorBubble1_3[SIZE_1];
    int VetorBubble2_1[SIZE_2];
    int VetorBubble2_2[SIZE_2];
    int VetorBubble2_3[SIZE_2];
    int VetorBubble3_1[SIZE_3];
    int VetorBubble3_2[SIZE_3];
    int VetorBubble3_3[SIZE_3];

    int VetorMerge1_1[SIZE_1];
    int VetorMerge1_2[SIZE_1];
    int VetorMerge1_3[SIZE_1];
    int VetorMerge2_1[SIZE_2];
    int VetorMerge2_2[SIZE_2];
    int VetorMerge2_3[SIZE_2];
    int VetorMerge3_1[SIZE_3];
    int VetorMerge3_2[SIZE_3];
    int VetorMerge3_3[SIZE_3];

    int VetorQuick1_1[SIZE_1];
    int VetorQuick1_2[SIZE_1];
    int VetorQuick1_3[SIZE_1];
    int VetorQuick2_1[SIZE_2];
    int VetorQuick2_2[SIZE_2];
    int VetorQuick2_3[SIZE_2];
    int VetorQuick3_1[SIZE_3];
    int VetorQuick3_2[SIZE_3];
    int VetorQuick3_3[SIZE_3];

    int VetorShell1_1[SIZE_1];
    int VetorShell1_2[SIZE_1];
    int VetorShell1_3[SIZE_1];
    int VetorShell2_1[SIZE_2];
    int VetorShell2_2[SIZE_2];
    int VetorShell2_3[SIZE_2];
    int VetorShell3_1[SIZE_3];
    int VetorShell3_2[SIZE_3];
    int VetorShell3_3[SIZE_3];



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


    for (int i = 0; i < SIZE_1; i++) {
        VetorSelection1_1[i] = VetorInsertion1_1[i];
        VetorSelection1_2[i] = VetorInsertion1_2[i];
        VetorSelection1_3[i] = VetorInsertion1_3[i];

        VetorBubble1_1[i] = VetorInsertion1_1[i];
        VetorBubble1_2[i] = VetorInsertion1_2[i];
        VetorBubble1_3[i] = VetorInsertion1_3[i];

        VetorMerge1_1[i] = VetorInsertion1_1[i];
        VetorMerge1_2[i] = VetorInsertion1_2[i];
        VetorMerge1_3[i] = VetorInsertion1_3[i];
        
        VetorQuick1_1[i] = VetorInsertion1_1[i];
        VetorQuick1_2[i] = VetorInsertion1_2[i];
        VetorQuick1_3[i] = VetorInsertion1_3[i];
        
        VetorShell1_1[i] = VetorInsertion1_1[i];
        VetorShell1_2[i] = VetorInsertion1_2[i];
        VetorShell1_3[i] = VetorInsertion1_3[i];
    }
    for (int i = 0; i < SIZE_2; i++) {
        VetorSelection2_1[i] = VetorInsertion2_1[i];
        VetorSelection2_2[i] = VetorInsertion2_2[i];
        VetorSelection2_3[i] = VetorInsertion2_3[i];

        VetorBubble2_1[i] = VetorInsertion2_1[i];
        VetorBubble2_2[i] = VetorInsertion2_2[i];
        VetorBubble2_3[i] = VetorInsertion2_3[i];

        VetorMerge2_1[i] = VetorInsertion2_1[i];
        VetorMerge2_2[i] = VetorInsertion2_2[i];
        VetorMerge2_3[i] = VetorInsertion2_3[i];
        
        VetorQuick2_1[i] = VetorInsertion2_1[i];
        VetorQuick2_2[i] = VetorInsertion2_2[i];
        VetorQuick2_3[i] = VetorInsertion2_3[i];
        
        VetorShell2_1[i] = VetorInsertion2_1[i];
        VetorShell2_2[i] = VetorInsertion2_2[i];
        VetorShell2_3[i] = VetorInsertion2_3[i];
    }
    for (int i = 0; i < SIZE_3; i++) {
        VetorSelection3_1[i] = VetorInsertion3_1[i];
        VetorSelection3_2[i] = VetorInsertion3_2[i];
        VetorSelection3_3[i] = VetorInsertion3_3[i];

        VetorBubble3_1[i] = VetorInsertion3_1[i];
        VetorBubble3_2[i] = VetorInsertion3_2[i];
        VetorBubble3_3[i] = VetorInsertion3_3[i];

        VetorMerge3_1[i] = VetorInsertion3_1[i];
        VetorMerge3_2[i] = VetorInsertion3_2[i];
        VetorMerge3_3[i] = VetorInsertion3_3[i];
        
        VetorQuick3_1[i] = VetorInsertion3_1[i];
        VetorQuick3_2[i] = VetorInsertion3_2[i];
        VetorQuick3_3[i] = VetorInsertion3_3[i];
        
        VetorShell3_1[i] = VetorInsertion3_1[i];
        VetorShell3_2[i] = VetorInsertion3_2[i];
        VetorShell3_3[i] = VetorInsertion3_3[i];
    }

    //INSERTION SORT
    int comparacoesInsertion = 0, trocasInsertion = 0;


    //TAMANHO 100
    comparacoesInsertion = 0, trocasInsertion = 0;
    
    inicio1 = clock();
    insertionSort(VetorInsertion1_1, SIZE_1, &comparacoesInsertion, &trocasInsertion);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Insertion Sort Preenchido Aleatorio (tamanho %d):\n", SIZE_1);
    printf("Comparacoes: %d\n", comparacoesInsertion);
    printf("Trocas: %d\n", trocasInsertion);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");
    
    comparacoesInsertion = 0, trocasInsertion = 0;
    inicio1 = clock();
    insertionSort(VetorInsertion1_2, SIZE_1, &comparacoesInsertion, &trocasInsertion);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Insertion Sort Ordenado Ascendente (tamanho %d):\n", SIZE_1);
    printf("Comparacoes: %d\n", comparacoesInsertion);
    printf("Trocas: %d\n", trocasInsertion);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesInsertion = 0, trocasInsertion = 0;
    inicio1 = clock();
    insertionSort(VetorInsertion1_3, SIZE_1, &comparacoesInsertion, &trocasInsertion);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Insertion Sort Ordenado Descendente (tamanho %d):\n", SIZE_1);
    printf("Comparacoes: %d\n", comparacoesInsertion);
    printf("Trocas: %d\n", trocasInsertion);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");



    //TAMANHO 1000
    inicio1 = clock();
    insertionSort(VetorInsertion2_1, SIZE_2, &comparacoesInsertion, &trocasInsertion);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Insertion Sort Preenchido Aleatorio (tamanho %d):\n", SIZE_2);
    printf("Comparacoes: %d\n", comparacoesInsertion);
    printf("Trocas: %d\n", trocasInsertion);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesInsertion = 0, trocasInsertion = 0;
    inicio1 = clock();
    insertionSort(VetorInsertion2_2, SIZE_2, &comparacoesInsertion, &trocasInsertion);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Insertion Sort Ordenado Ascendente (tamanho %d):\n", SIZE_2);
    printf("Comparacoes: %d\n", comparacoesInsertion);
    printf("Trocas: %d\n", trocasInsertion);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesInsertion = 0, trocasInsertion = 0;
    inicio1 = clock();
    insertionSort(VetorInsertion2_3, SIZE_2, &comparacoesInsertion, &trocasInsertion);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Insertion Sort Ordenado Descendente (tamanho %d):\n", SIZE_2);
    printf("Comparacoes: %d\n", comparacoesInsertion);
    printf("Trocas: %d\n", trocasInsertion);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");


    //TAMANHO 10000
    comparacoesInsertion = 0, trocasInsertion = 0;
    inicio1 = clock();
    insertionSort(VetorInsertion3_1, SIZE_3, &comparacoesInsertion, &trocasInsertion);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Insertion Sort Preenchido Aleatorio (tamanho %d):\n", SIZE_3);
    printf("Comparacoes: %d\n", comparacoesInsertion);
    printf("Trocas: %d\n", trocasInsertion);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");
    
    comparacoesInsertion = 0, trocasInsertion = 0;
    inicio1 = clock();
    insertionSort(VetorInsertion3_2, SIZE_3, &comparacoesInsertion, &trocasInsertion);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Insertion Sort Ordenado Ascendente (tamanho %d):\n", SIZE_3);
    printf("Comparacoes: %d\n", comparacoesInsertion);
    printf("Trocas: %d\n", trocasInsertion);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesInsertion = 0, trocasInsertion = 0;
    inicio1 = clock();
    insertionSort(VetorInsertion3_3, SIZE_3, &comparacoesInsertion, &trocasInsertion);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Insertion Sort Ordenado Descendente (tamanho %d):\n", SIZE_3);
    printf("Comparacoes: %d\n", comparacoesInsertion);
    printf("Trocas: %d\n", trocasInsertion);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");


    //------------------------------------------------------------------------------------------------------
    //SELECTION SORT
    int comparacoesSelection = 0, trocasSelection = 0;

    //TAMANHO 100
    comparacoesSelection = 0, trocasSelection = 0;

    inicio1 = clock();
    selectionSort(VetorSelection1_1, SIZE_1, &comparacoesSelection, &trocasSelection);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Selection Sort Preenchido Aleatorio (tamanho %d):\n", SIZE_1);
    printf("Comparacoes: %d\n", comparacoesSelection);
    printf("Trocas: %d\n", trocasSelection);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesSelection = 0, trocasSelection = 0;
    inicio1 = clock();
    selectionSort(VetorSelection1_2, SIZE_1, &comparacoesSelection, &trocasSelection);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Selection Sort Ordenado Ascendente (tamanho %d):\n", SIZE_1);
    printf("Comparacoes: %d\n", comparacoesSelection);
    printf("Trocas: %d\n", trocasSelection);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesSelection = 0, trocasSelection = 0;
    inicio1 = clock();
    selectionSort(VetorSelection1_3, SIZE_1, &comparacoesSelection, &trocasSelection);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Selection Sort Ordenado Descendente (tamanho %d):\n", SIZE_1);
    printf("Comparacoes: %d\n", comparacoesSelection);
    printf("Trocas: %d\n", trocasSelection);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    //TAMANHO 1000
    inicio1 = clock();
    selectionSort(VetorSelection2_1, SIZE_2, &comparacoesSelection, &trocasSelection);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Selection Sort Preenchido Aleatorio (tamanho %d):\n", SIZE_2);
    printf("Comparacoes: %d\n", comparacoesSelection);
    printf("Trocas: %d\n", trocasSelection);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesSelection = 0, trocasSelection = 0;
    inicio1 = clock();
    selectionSort(VetorSelection2_2, SIZE_2, &comparacoesSelection, &trocasSelection);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Selection Sort Ordenado Ascendente (tamanho %d):\n", SIZE_2);
    printf("Comparacoes: %d\n", comparacoesSelection);
    printf("Trocas: %d\n", trocasSelection);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesSelection = 0, trocasSelection = 0;
    inicio1 = clock();
    selectionSort(VetorSelection2_3, SIZE_2, &comparacoesSelection, &trocasSelection);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Selection Sort Ordenado Descendente (tamanho %d):\n", SIZE_2);
    printf("Comparacoes: %d\n", comparacoesSelection);
    printf("Trocas: %d\n", trocasSelection);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    //TAMANHO 10000
    comparacoesSelection = 0, trocasSelection = 0;
    inicio1 = clock();
    selectionSort(VetorSelection3_1, SIZE_3, &comparacoesSelection, &trocasSelection);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Selection Sort Preenchido Aleatorio (tamanho %d):\n", SIZE_3);
    printf("Comparacoes: %d\n", comparacoesSelection);
    printf("Trocas: %d\n", trocasSelection);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesSelection = 0, trocasSelection = 0;
    inicio1 = clock();
    selectionSort(VetorSelection3_2, SIZE_3, &comparacoesSelection, &trocasSelection);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Selection Sort Ordenado Ascendente (tamanho %d):\n", SIZE_3);
    printf("Comparacoes: %d\n", comparacoesSelection);
    printf("Trocas: %d\n", trocasSelection);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesSelection = 0, trocasSelection = 0;
    inicio1 = clock();
    selectionSort(VetorSelection3_3, SIZE_3, &comparacoesSelection, &trocasSelection);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Selection Sort Ordenado Descendente (tamanho %d):\n", SIZE_3);
    printf("Comparacoes: %d\n", comparacoesSelection);
    printf("Trocas: %d\n", trocasSelection);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");



    //BUBBLE SORT
    int comparacoesBubble = 0, trocasBubble = 0;

    // TAMANHO 100
    comparacoesBubble = 0, trocasBubble = 0;

    inicio1 = clock();
    bubbleSort(VetorBubble1_1, SIZE_1, &comparacoesBubble, &trocasBubble);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Bubble Sort Preenchido Aleatorio (tamanho %d):\n", SIZE_1);
    printf("Comparacoes: %d\n", comparacoesBubble);
    printf("Trocas: %d\n", trocasBubble);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesBubble = 0, trocasBubble = 0;
    inicio1 = clock();
    bubbleSort(VetorBubble1_2, SIZE_1, &comparacoesBubble, &trocasBubble);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Bubble Sort Ordenado Ascendente (tamanho %d):\n", SIZE_1);
    printf("Comparacoes: %d\n", comparacoesBubble);
    printf("Trocas: %d\n", trocasBubble);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesBubble = 0, trocasBubble = 0;
    inicio1 = clock();
    bubbleSort(VetorBubble1_3, SIZE_1, &comparacoesBubble, &trocasBubble);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Bubble Sort Ordenado Descendente (tamanho %d):\n", SIZE_1);
    printf("Comparacoes: %d\n", comparacoesBubble);
    printf("Trocas: %d\n", trocasBubble);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    // TAMANHO 1000
    inicio1 = clock();
    bubbleSort(VetorBubble2_1, SIZE_2, &comparacoesBubble, &trocasBubble);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Bubble Sort Preenchido Aleatorio (tamanho %d):\n", SIZE_2);
    printf("Comparacoes: %d\n", comparacoesBubble);
    printf("Trocas: %d\n", trocasBubble);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesBubble = 0, trocasBubble = 0;
    inicio1 = clock();
    bubbleSort(VetorBubble2_2, SIZE_2, &comparacoesBubble, &trocasBubble);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Bubble Sort Ordenado Ascendente (tamanho %d):\n", SIZE_2);
    printf("Comparacoes: %d\n", comparacoesBubble);
    printf("Trocas: %d\n", trocasBubble);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesBubble = 0, trocasBubble = 0;
    inicio1 = clock();
    bubbleSort(VetorBubble2_3, SIZE_2, &comparacoesBubble, &trocasBubble);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Bubble Sort Ordenado Descendente (tamanho %d):\n", SIZE_2);
    printf("Comparacoes: %d\n", comparacoesBubble);
    printf("Trocas: %d\n", trocasBubble);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    // TAMANHO 10000
    comparacoesBubble = 0, trocasBubble = 0;
    inicio1 = clock();
    bubbleSort(VetorBubble3_1, SIZE_3, &comparacoesBubble, &trocasBubble);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Bubble Sort Preenchido Aleatorio (tamanho %d):\n", SIZE_3);
    printf("Comparacoes: %d\n", comparacoesBubble);
    printf("Trocas: %d\n", trocasBubble);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesBubble = 0, trocasBubble = 0;
    inicio1 = clock();
    bubbleSort(VetorBubble3_2, SIZE_3, &comparacoesBubble, &trocasBubble);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Bubble Sort Ordenado Ascendente (tamanho %d):\n", SIZE_3);
    printf("Comparacoes: %d\n", comparacoesBubble);
    printf("Trocas: %d\n", trocasBubble);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesBubble = 0, trocasBubble = 0;
    inicio1 = clock();
    bubbleSort(VetorBubble3_3, SIZE_3, &comparacoesBubble, &trocasBubble);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Bubble Sort Ordenado Descendente (tamanho %d):\n", SIZE_3);
    printf("Comparacoes: %d\n", comparacoesBubble);
    printf("Trocas: %d\n", trocasBubble);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");



    // MERGESORT
    int comparacoesMerge = 0, trocasMerge = 0;
    int tamanho1 = SIZE_1;
    int tamanho2 = SIZE_2;
    int tamanho3 = SIZE_3;

    // TAMANHO 100
    comparacoesMerge = 0, trocasMerge = 0;

    inicio1 = clock();
    mergeSort(VetorMerge1_1, 0, tamanho1-1, &comparacoesMerge, &trocasMerge);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Merge Sort Preenchido Aleatorio (tamanho %d):\n", SIZE_1);
    printf("Comparacoes: %d\n", comparacoesMerge);
    printf("Trocas: %d\n", trocasMerge);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesMerge = 0, trocasMerge = 0;
    inicio1 = clock();
    mergeSort(VetorMerge1_2, 0, tamanho1-1, &comparacoesMerge, &trocasMerge);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Merge Sort Ordenado Ascendente (tamanho %d):\n", SIZE_1);
    printf("Comparacoes: %d\n", comparacoesMerge);
    printf("Trocas: %d\n", trocasMerge);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesMerge = 0, trocasMerge = 0;
    inicio1 = clock();
    mergeSort(VetorMerge1_3, 0, tamanho1-1, &comparacoesMerge, &trocasMerge);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Merge Sort Ordenado Descendente (tamanho %d):\n", SIZE_1);
    printf("Comparacoes: %d\n", comparacoesMerge);
    printf("Trocas: %d\n", trocasMerge);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    // TAMANHO 1000
    inicio1 = clock();
    mergeSort(VetorMerge2_1, 0, tamanho2-1, &comparacoesMerge, &trocasMerge);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Merge Sort Preenchido Aleatorio (tamanho %d):\n", SIZE_2);
    printf("Comparacoes: %d\n", comparacoesMerge);
    printf("Trocas: %d\n", trocasMerge);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesMerge = 0, trocasMerge = 0;
    inicio1 = clock();
    mergeSort(VetorMerge2_2, 0, tamanho2-1, &comparacoesMerge, &trocasMerge);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Merge Sort Ordenado Ascendente (tamanho %d):\n", SIZE_2);
    printf("Comparacoes: %d\n", comparacoesMerge);
    printf("Trocas: %d\n", trocasMerge);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesMerge = 0, trocasMerge = 0;
    inicio1 = clock();
    mergeSort(VetorMerge2_3, 0, tamanho2-1, &comparacoesMerge, &trocasMerge);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Merge Sort Ordenado Descendente (tamanho %d):\n", SIZE_2);
    printf("Comparacoes: %d\n", comparacoesMerge);
    printf("Trocas: %d\n", trocasMerge);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    // TAMANHO 10000
    comparacoesMerge = 0, trocasMerge = 0;
    inicio1 = clock();
    mergeSort(VetorMerge3_1, 0, tamanho3-1, &comparacoesMerge, &trocasMerge);
    fim1 = clock(); 
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Merge Sort Preenchido Aleatorio (tamanho %d):\n", SIZE_3);
    printf("Comparacoes: %d\n", comparacoesMerge);
    printf("Trocas: %d\n", trocasMerge);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesMerge = 0, trocasMerge = 0;
    inicio1 = clock();
    mergeSort(VetorMerge3_2, 0, tamanho3-1, &comparacoesMerge, &trocasMerge);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Merge Sort Ordenado Ascendente (tamanho %d):\n", SIZE_3);
    printf("Comparacoes: %d\n", comparacoesMerge);
    printf("Trocas: %d\n", trocasMerge);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesMerge = 0, trocasMerge = 0;
    inicio1 = clock();
    mergeSort(VetorMerge3_3, 0, tamanho3-1, &comparacoesMerge, &trocasMerge);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Merge Sort Ordenado Descendente (tamanho %d):\n", SIZE_3);
    printf("Comparacoes: %d\n", comparacoesMerge);
    printf("Trocas: %d\n", trocasMerge);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");



    // QUICKSORT
    int comparacoesQuick = 0, trocasQuick = 0;

    // TAMANHO 100
    comparacoesQuick = 0, trocasQuick = 0;

    inicio1 = clock();
    quickSort(VetorQuick1_1, 0, tamanho1-1, &comparacoesQuick, &trocasQuick);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Quick Sort Preenchido Aleatorio (tamanho %d):\n", SIZE_1);
    printf("Comparacoes: %d\n", comparacoesQuick);
    printf("Trocas: %d\n", trocasQuick);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesQuick = 0, trocasQuick = 0;
    inicio1 = clock();
    quickSort(VetorQuick1_2, 0, tamanho1-1, &comparacoesQuick, &trocasQuick);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Quick Sort Ordenado Ascendente (tamanho %d):\n", SIZE_1);
    printf("Comparacoes: %d\n", comparacoesQuick);
    printf("Trocas: %d\n", trocasQuick);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesQuick = 0, trocasQuick = 0;
    inicio1 = clock();
    quickSort(VetorQuick1_3, 0, tamanho1-1, &comparacoesQuick, &trocasQuick);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Quick Sort Ordenado Descendente (tamanho %d):\n", SIZE_1);
    printf("Comparacoes: %d\n", comparacoesQuick);
    printf("Trocas: %d\n", trocasQuick);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    // TAMANHO 1000
    inicio1 = clock();
    quickSort(VetorQuick2_1, 0, tamanho2-1, &comparacoesQuick, &trocasQuick);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Quick Sort Preenchido Aleatorio (tamanho %d):\n", SIZE_2);
    printf("Comparacoes: %d\n", comparacoesQuick);
    printf("Trocas: %d\n", trocasQuick);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesQuick = 0, trocasQuick = 0;
    inicio1 = clock();
    quickSort(VetorQuick2_2, 0, tamanho2-1, &comparacoesQuick, &trocasQuick);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Quick Sort Ordenado Ascendente (tamanho %d):\n", SIZE_2);
    printf("Comparacoes: %d\n", comparacoesQuick);
    printf("Trocas: %d\n", trocasQuick);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesQuick = 0, trocasQuick = 0;
    inicio1 = clock();
    quickSort(VetorQuick2_3, 0, tamanho2-1, &comparacoesQuick, &trocasQuick);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Quick Sort Ordenado Descendente (tamanho %d):\n", SIZE_2);
    printf("Comparacoes: %d\n", comparacoesQuick);
    printf("Trocas: %d\n", trocasQuick);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    // TAMANHO 10000
    comparacoesQuick = 0, trocasQuick = 0;
    inicio1 = clock();
    quickSort(VetorQuick3_1, 0, tamanho3-1, &comparacoesQuick, &trocasQuick);
    fim1 = clock(); 
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Quick Sort Preenchido Aleatorio (tamanho %d):\n", SIZE_3);
    printf("Comparacoes: %d\n", comparacoesQuick);
    printf("Trocas: %d\n", trocasQuick);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesQuick = 0, trocasQuick = 0;
    inicio1 = clock();
    quickSort(VetorQuick3_2, 0, tamanho3-1, &comparacoesQuick, &trocasQuick);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Quick Sort Ordenado Ascendente (tamanho %d):\n", SIZE_3);
    printf("Comparacoes: %d\n", comparacoesQuick);
    printf("Trocas: %d\n", trocasQuick);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesQuick = 0, trocasQuick = 0;
    inicio1 = clock();
    quickSort(VetorQuick3_3, 0, tamanho3-1, &comparacoesQuick, &trocasQuick);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Quick Sort Ordenado Descendente (tamanho %d):\n", SIZE_3);
    printf("Comparacoes: %d\n", comparacoesQuick);
    printf("Trocas: %d\n", trocasQuick);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");


    int comparacoesShell = 0, trocasShell = 0;

    // TAMANHO 100
    comparacoesShell = 0, trocasShell = 0;

    inicio1 = clock();
    shellSort(VetorShell1_1, SIZE_1, &comparacoesShell, &trocasShell);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Shell Sort Preenchido Aleatorio (tamanho %d):\n", SIZE_1);
    printf("Comparacoes: %d\n", comparacoesShell);
    printf("Trocas: %d\n", trocasShell);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesShell = 0, trocasShell = 0;
    inicio1 = clock();
    shellSort(VetorShell1_2, SIZE_1, &comparacoesShell, &trocasShell);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Shell Sort Ordenado Ascendente (tamanho %d):\n", SIZE_1);
    printf("Comparacoes: %d\n", comparacoesShell);
    printf("Trocas: %d\n", trocasShell);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesShell = 0, trocasShell = 0;
    inicio1 = clock();
    shellSort(VetorShell1_3, SIZE_1, &comparacoesShell, &trocasShell);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Shell Sort Ordenado Descendente (tamanho %d):\n", SIZE_1);
    printf("Comparacoes: %d\n", comparacoesShell);
    printf("Trocas: %d\n", trocasShell);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    // TAMANHO 1000
    inicio1 = clock();
    shellSort(VetorShell2_1, SIZE_2, &comparacoesShell, &trocasShell);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Shell Sort Preenchido Aleatorio (tamanho %d):\n", SIZE_2);
    printf("Comparacoes: %d\n", comparacoesShell);
    printf("Trocas: %d\n", trocasShell);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesShell = 0, trocasShell = 0;
    inicio1 = clock();
    shellSort(VetorShell2_2, SIZE_2, &comparacoesShell, &trocasShell);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Shell Sort Ordenado Ascendente (tamanho %d):\n", SIZE_2);
    printf("Comparacoes: %d\n", comparacoesShell);
    printf("Trocas: %d\n", trocasShell);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesShell = 0, trocasShell = 0;
    inicio1 = clock();
    shellSort(VetorShell2_3, SIZE_2, &comparacoesShell, &trocasShell);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Shell Sort Ordenado Descendente (tamanho %d):\n", SIZE_2);
    printf("Comparacoes: %d\n", comparacoesShell);
    printf("Trocas: %d\n", trocasShell);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    // TAMANHO 10000
    comparacoesShell = 0, trocasShell = 0;
    inicio1 = clock();
    shellSort(VetorShell3_1, SIZE_3, &comparacoesShell, &trocasShell);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Shell Sort Preenchido Aleatorio (tamanho %d):\n", SIZE_3);
    printf("Comparacoes: %d\n", comparacoesShell);
    printf("Trocas: %d\n", trocasShell);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesShell = 0, trocasShell = 0;
    inicio1 = clock();
    shellSort(VetorShell3_2, SIZE_3, &comparacoesShell, &trocasShell);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Shell Sort Ordenado Ascendente (tamanho %d):\n", SIZE_3);
    printf("Comparacoes: %d\n", comparacoesShell);
    printf("Trocas: %d\n", trocasShell);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");

    comparacoesShell = 0, trocasShell = 0;
    inicio1 = clock();
    shellSort(VetorShell3_3, SIZE_3, &comparacoesShell, &trocasShell);
    fim1 = clock();
    tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    printf("Shell Sort Ordenado Descendente (tamanho %d):\n", SIZE_3);
    printf("Comparacoes: %d\n", comparacoesShell);
    printf("Trocas: %d\n", trocasShell);
    printf("Tempo: %f segundos\n", tempo1);
    printf("\n");


    return 0;
}
