// A Write a program to implement merge sort algorithm

#include "stdio.h"
#include "time.h"
#include "stdlib.h"

void mergeSort(int a[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = 0;
    
    int *b = (int *)malloc((high - low + 1) * sizeof(int));

    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        b[k] = a[i];
        i++;
        k++;
    }

    while (j <= high) {
        b[k] = a[j];
        j++;
        k++;
    }

    for (i = low, k = 0; i <= high; i++, k++) {
        a[i] = b[k];
    }

    free(b); 
}

void merge(int a[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        
        merge(a, low, mid);
        merge(a, mid + 1, high);
        
        mergeSort(a, low, mid, high);
    }
}


void read_array(const char *fileName, int n)
{
    FILE *fp = fopen(fileName, "r");
    int a[n];
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &a[i]);
    }
    fclose(fp);
    clock_t start_time = clock();
    merge(a,0,n-1);
    clock_t end_time = clock();
    double cpu = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("%-25s | Size: %-7d | CPU Time: %f seconds\n", fileName, n, cpu);
}

int main()
{
    read_array("../Case_1_Best.txt", 1000);
    read_array("../Case_1_Avg.txt", 1000);
    read_array("../Case_1_Worst.txt", 1000);

    read_array("../Case_2_Best.txt", 10000);
    read_array("../Case_2_Avg.txt", 10000);
    read_array("../Case_2_Worst.txt", 10000);

    read_array("../Case_3_Best.txt", 100000);
    read_array("../Case_3_Avg.txt", 100000);
    read_array("../Case_3_Worst.txt", 100000);
}