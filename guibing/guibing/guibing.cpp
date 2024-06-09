#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  

// 合并两个已排序的数组  
void merge(int arr[], int left_start, int left_end, int right_start, int right_end) {
    int* left = (int*)malloc((left_end - left_start + 1) * sizeof(int));
    int* right = (int*)malloc((right_end - right_start + 1) * sizeof(int));
    if (!left || !right) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // 复制数据到临时数组  
    for (int i = 0; left_start + i <= left_end; i++) {
        left[i] = arr[left_start + i];
    }
    for (int i = 0; right_start + i <= right_end; i++) {
        right[i] = arr[right_start + i];
    }

    int i = 0, j = 0, k = left_start;

    // 合并临时数组回原数组  
    while (i <= left_end - left_start && j <= right_end - right_start) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        }
        else {
            arr[k++] = right[j++];
        }
    }

    // 复制左数组的剩余部分  
    while (i <= left_end - left_start) {
        arr[k++] = left[i++];
    }

    // 复制右数组的剩余部分（这一步在这种情况下其实是不必要的，但保持完整性）  
    while (j <= right_end - right_start) {
        arr[k++] = right[j++];
    }

    free(left);
    free(right);
}

// 归并排序  
void mergeSort(int arr[], int start, int end) {
    if (start >= end) {
        return; // 无需排序  
    }

    int mid = (start + end) / 2;

    // 递归对左右两部分进行排序  
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    // 合并左右两部分  
    merge(arr, start, mid, mid + 1, end);
}

void generateAndSort(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // 生成随机数  
    srand((unsigned int)time(NULL)); // 设置随机数种子  
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100000; // 生成0到99999的随机整数  
    }

    // 测量排序时间  
    clock_t start = clock();
    mergeSort(arr, 0, size - 1);
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