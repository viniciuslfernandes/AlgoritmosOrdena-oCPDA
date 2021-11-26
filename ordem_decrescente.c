#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define TAM 100000

void constroiHeap(int *p_vetor, int tamanho, int indice_raiz);
void HeapSort(int *p_vetor, int tamanho);

void mergeSort(int vec[], int vecSize);
void merge(int vec[], int vecSize);
void insertion_sort(int vetor[]);
void selection_sort(int vetor[]);
void bubbleSort(int array[], int length);
void quicksort(int values[], int began, int end);
void inicializarAleatoriamente(int v[], int n);
void inicializarOrdemCrescente(int v[], int n);
void inicializarOrdemDecrescente(int v[], int n);

void main(){
     printf("\n\nTESTE DE ORDEM DECRESCENTE\n\n");
    srand(time(NULL));
    int v[TAM], i;
    inicializarOrdemDecrescente(v, TAM);
    double start, stop, elapsed;
    start = (double) clock() / CLOCKS_PER_SEC;
    bubbleSort(v,TAM);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
     printf("\n\nO tempo gasto no BubbleSort foi: %f segundos\n\n", elapsed);

    inicializarOrdemDecrescente(v, TAM);
    start = 0;
    stop = 0;
    start = (double) clock() / CLOCKS_PER_SEC;
    quicksort(v,0,TAM);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;

    printf("\n\nO tempo gasto no QuickSort foi: %f segundos\n\n", elapsed);

    inicializarOrdemDecrescente(v, TAM);
    start = 0;
    stop = 0;
    start = (double) clock() / CLOCKS_PER_SEC;
    selection_sort(v);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;

    printf("\n\nO tempo gasto no SeletionSort foi: %f segundos\n\n", elapsed);

    
    inicializarOrdemDecrescente(v, TAM);
    start = 0;
    stop = 0;
    start = (double) clock() / CLOCKS_PER_SEC;
    insertion_sort(v);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;

   printf("\n\nO tempo gasto no insertionSort foi: %f segundos\n\n", elapsed);

    inicializarOrdemDecrescente(v, TAM);
    start = 0;
    stop = 0;
    start = (double) clock() / CLOCKS_PER_SEC;
    mergeSort(v,TAM);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;

       printf("\n\nO tempo gasto no MergeSort foi: %f segundos\n\n", elapsed);

    inicializarOrdemDecrescente(v, TAM);
    start = 0;
    stop = 0;
    start = (double)clock() / CLOCKS_PER_SEC;
    constroiHeap(v,TAM,0);
    HeapSort(v,TAM);
    stop = (double)clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;

    printf("\n\nO tempo gasto no HeapSort foi: %f segundos\n\n", elapsed);
}



void bubbleSort(int array[], int length)
{
    int i, j;
    for(i = length - 1; i > 0; i--) {
        for(j = 0; j < i; j++) {
            if(array[j] > array[j+1])
            {
                int temp;
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void quicksort(int values[], int began, int end)
{
    int i, j, pivo, aux;
    i = began;
    j = end-1;
    pivo = values[(began+end)/2];
    while(i <= j)
    {
        while(values[i] < pivo && i < end) i++;
        while(values[j] > pivo && j > began) j--;
        if(i <= j)
        {
            aux = values[i];
            values[i] = values[j];
            values[j] = aux;
            i++;
            j--;
        }
    }
    if(j > began)
        quicksort(values, began, j+1);
    if(i < end)
        quicksort(values, i, end);
}

void inicializarAleatoriamente(int v[], int n){
    int i;
    for(i = 0; i < n; i++)
        v[i] = rand();
}

void inicializarOrdemCrescente(int v[], int n){
    int i;
    for(i = 0; i < n; i++)
        v[i] = i;
}

void inicializarOrdemDecrescente(int v[], int n){
    int i;
    for(i = 0; i < n; i++)
        v[i] = n-i;
}

void insertion_sort(int vetor[]){
    int i, temp, j;
    for(i = 1; i < TAM; i++)
    {
        temp= vetor[i];
        j= i-1;
        while (j>=0 && temp < vetor[j])
        {
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = temp;
    }
}

void selection_sort(int vetor[]){
    int i, j, min, temp;
    for(i =0; i < TAM; i++){
        min=i;
        for(j=i +1; j<TAM; j++){
            if(vetor[j]<vetor[min]){
                min = j;
            }
        }
        if(vetor[i] != vetor[min])
        {
            temp=vetor[i];
            vetor[i] = vetor[min];
            vetor[min]=temp;
        }
    }
}

void merge(int vec[], int vecSize){
    int mid;
    int i, j, k;
    int *tmp;
    tmp = (int*) malloc(vecSize * sizeof(int));
    if(tmp == NULL){
        exit(1);
    }
    mid = vecSize/2;
    i=0;
    j=mid;
    k=0;
    while(i<mid && j<vecSize){
        if(vec[i]<vec[j]){
            tmp[k] = vec[i];
            ++i;
        }
        else{
            tmp[k] = vec[j];
            ++j;
        }
        ++k;
    }
    if(i==mid){
        while(j<vecSize){
            tmp[k]= vec[j];
            ++j;
            ++k;
        }
    }
    else{
        while(i<mid){
            tmp[k]=vec[i];
            ++i;
            ++k;
        }
    }
    for(i=0; i < vecSize; i++){
        vec[i] = tmp[i];
    }
    free(tmp);
}

void mergeSort(int vec[], int vecSize) {
    int mid;

    if(vecSize > 1) {
        mid = vecSize / 2;
        mergeSort(vec, mid);
        mergeSort(vec + mid, vecSize - mid);
        merge(vec, vecSize);
    }
}


void constroiHeap(int *p_vetor, int tamanho, int indice_raiz)
{
    int ramificacao, valor;
    valor = p_vetor[indice_raiz];

    while (indice_raiz <= tamanho / 2)
    {
        ramificacao = 2 * indice_raiz;

        if (ramificacao < tamanho && p_vetor[ramificacao] < p_vetor[ramificacao + 1])
            ramificacao++;

        if (valor >= p_vetor[ramificacao]) //Identifica o max-heap
            break;

        p_vetor[indice_raiz] = p_vetor[ramificacao];
        indice_raiz = ramificacao;
    }
    p_vetor[indice_raiz] = valor;
}

void HeapSort(int *p_vetor, int tamanho)
{
    int indice, troca;
    for (indice = tamanho / 2; indice >= 0; indice--)
        constroiHeap(p_vetor, tamanho, indice);

    while (tamanho > 0)
    {
        troca = p_vetor[0];
        p_vetor[0] = p_vetor[tamanho];
        p_vetor[tamanho] = troca;
        constroiHeap(p_vetor, --tamanho, 0);
    }
}