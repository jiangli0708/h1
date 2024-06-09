#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,  
        // to one position ahead of their current position  
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    insertionSort(arr, size);
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