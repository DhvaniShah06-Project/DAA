// A Write a program to sort array elements using heap sort.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Max_Heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        Max_Heapify(arr, n, largest);
    }
}

void Heap_Sort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Max_Heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        Max_Heapify(arr, i, 0);
    }
}

void read_array(const char *fileName, int n)
{

    FILE *fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        printf("Error: Could not open file %s\n", fileName);
        return;
    }
    int a[n];
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &a[i]);
    }
    fclose(fp);

    clock_t start_time = clock();
    Heap_Sort(a, n);
    clock_t end_time = clock();

    double cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("%-25s | Size: %-7d | CPU Time: %f seconds\n", fileName, n, cpu_time_used);
}

int main()
{

    read_array("Heap_Case_1_Best.txt", 1000);
    read_array("Heap_Case_1_Avg.txt", 1000);
    read_array("Heap_Case_1_Worst.txt", 1000);

    read_array("Heap_Case_2_Best.txt", 10000);
    read_array("Heap_Case_2_Avg.txt", 10000);
    read_array("Heap_Case_2_Worst.txt", 10000);

    read_array("Heap_Case_3_Best.txt", 100000);
    read_array("Heap_Case_3_Avg.txt", 100000);
    read_array("Heap_Case_3_Worst.txt", 100000);

    return 0;
}
