#include <stdio.h>

// Função para mesclar duas metades do array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Tamanho da primeira metade
    int n2 = right - mid;    // Tamanho da segunda metade

    int L[n1], R[n2]; // Arrays temporários para as metades

    // Copiando dados para os arrays temporários L[] e R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;  // Índice inicial do primeiro subarray
    int j = 0;  // Índice inicial do segundo subarray
    int k = left; // Índice inicial do subarray mesclado

    // Mesclando os arrays temporários de volta no array principal arr[]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiando os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiando os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função recursiva do Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Encontra o meio do array

        // Ordena a primeira e a segunda metade
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Mescla as duas metades ordenadas
        merge(arr, left, mid, right);
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}