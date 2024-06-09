#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void generateAndSort(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed for %d elements.\n", size);
        return;
    }

    // Generate random numbers  
    srand(time(NULL)); // Only call this once, so move it to main  
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000; // Generate random numbers between 0 and 9999  
    }

    // Measure sorting time  
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    bubbleSort(arr, size);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken to sort %d numbers: %f seconds\n", size, cpu_time_used);

    free(arr);
}

int main() {
    int sizes[] = { 10, 100, 1000, 10000, 100000 };
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    // Call srand only once, before the loop  
    srand(time(NULL));

    for (int i = 0; i < numSizes; i++) {
        generateAndSort(sizes[i]);
    }

    return 0;
}