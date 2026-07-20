#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *read_array(const char *fileName, int n) {
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", fileName);
        return NULL;
    }
    
    // Allocate memory dynamically so it is not lost when the function returns
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

int main() {
    int search, low, mid, high, flag = 0;
    
    printf("Enter element to search : ");
    scanf("%d", &search);
    
    low = 0;
    high = 999; 
    
    clock_t start_time = clock();
    
    // Adjusted path assuming the file is in the current working directory
    int *arr = read_array("../Case_1_Best.txt", 1000); 
    
    if (arr != NULL) {
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (arr[mid] == search) {
                printf("Element found at index: %d\n", mid);
                flag = 1;
                break;
            } else if (arr[mid] < search) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        if (flag == 0) {
            printf("Element not found\n");
        }
        

        free(arr);
    }

    clock_t end_time = clock();
    double cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("%-25s | Size: %-7d | CPU Time: %.6f seconds\n", "Case_1_Best.txt", 1000, cpu_time_used);
    
    return 0;
}
