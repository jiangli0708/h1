#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void generateAndSort(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        perror("Memory allocation failed");
        return;
    }

    // Generate random numbers  
    srand((unsigned int)time(NULL)); // Seed the random number generator  
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100000; // Random numbers from 0 to 99999  
    }

    // Measure sorting time  
    clock_t start = clock();
    quickSort(arr, 0, size - 1);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken to sort %d numbers: %f seconds\n", size, time_spent);

    free(arr);
}

int main() {
    int sizes[] = { 10, 100, 1000, 10000, 100000 };
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < numSizes; i++) {
        generateAndSort(sizes[i]);
    }

    return 0;
}