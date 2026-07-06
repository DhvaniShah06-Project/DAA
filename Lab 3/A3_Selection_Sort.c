// A Write a program to sort array elements using selection sort. Read n elements given by user from file and observe cpu time taken.

#include "stdio.h"
#include "time.h"

void Selection_Sort(int a[], int n)
{
    int i = 0;
    for (; i <= n - 2; i++)
    {
        int min_index = i;
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
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
    Selection_Sort(a, n);
    clock_t end_time = clock();
    double cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("%-30s | Size: %d | CPU Time: %f\n", fileName, n, cpu_time_used);
}

void main()
{
    read_array("Selection_Sort_Case_1_Best.txt", 1000);
    read_array("Selection_Sort_Case_1_Avg.txt", 1000);
    read_array("Selection_Sort_Case_1_Worst.txt", 1000);

    read_array("Selection_Sort_Case_2_Best.txt", 10000);
    read_array("Selection_Sort_Case_2_Avg.txt", 10000);
    read_array("Selection_Sort_Case_2_Worst.txt", 10000);

    read_array("Selection_Sort_Case_3_Best.txt", 100000);
    read_array("Selection_Sort_Case_3_Avg.txt", 100000);
    read_array("Selection_Sort_Case_3_Worst.txt", 100000);
}