#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  

// 交换两个数的函数  
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 选择排序函数  
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

// 生成随机数组并排序，测量时间  
void generateAndSort(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // 设置随机数种子  
    srand((unsigned int)time(NULL));

    // 生成随机数  
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100000; // 生成0到99999的随机整数  
    }

    // 测量排序时间  
    clock_t start = clock();
    selectionSort(arr, size);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken to sort %d numbers: %f seconds\n", size, time_spent);

    // 释放内存  
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