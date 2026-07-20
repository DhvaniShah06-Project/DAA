#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *read_array(const char *fileName, int n) {
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", fileName);
        return NULL;
    }
    
    int *a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed\n");
        fclose(fp);
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &a[i]);
    }
    fclose(fp);
    return a;
}


int Binary_Search(int a[], int low, int high, int search) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (a[mid] == search) {
        return mid;
    }
    if (a[mid] > search) {
        return Binary_Search(a, low, mid - 1, search);
    }
    return Binary_Search(a, mid + 1, high, search);
}

int main() {
    int search, flag = 0;
    
    printf("Enter element to search : ");
    scanf("%d", &search);
    
    clock_t start_time = clock();
    
   
    int *arr = read_array("../Case_3_Best.txt", 100000); 
    
    if (arr != NULL) {
        int result = Binary_Search(arr, 0, 99999, search);
        
        if (result == -1) {
            printf("Element not found\n");
        } else {
            printf("Element found at index: %d\n", result);
        }
        
        free(arr);
    }

    clock_t end_time = clock();
    double cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("%-25s | Size: %-7d | CPU Time: %.6f seconds\n", "Case_1_Best.txt", 1000, cpu_time_used);
    
    return 0;
}
