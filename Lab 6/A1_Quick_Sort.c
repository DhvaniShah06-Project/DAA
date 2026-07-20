// A Write a program to implement quick sort algorithm.

#include "stdio.h"
#include "time.h"
#include "stdlib.h"

void Quick_Sort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int j = ub, i = lb, key = a[lb];
        while (i < j)
        {

            while (i < ub && a[i] < key)
            {
                i++;
            }

            while (a[j] > key)
            {
                j--;
            }
            if (i < j)
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                
            }
        }
        int temp = a[lb];
        a[lb] = a[j];
        a[j] = temp;
        Quick_Sort(a, lb, j - 1);
        Quick_Sort(a, j + 1, ub);
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
    Quick_Sort(a, 0, n - 1);
    clock_t end_time = clock();
    double cpu = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("%-25s | Size: %-7d | CPU Time: %f seconds\n", fileName, n, cpu);
}

int main()
{
    // read_array("../Case_1_Best.txt", 1000);
    // read_array("../Case_1_Avg.txt", 1000);
    // read_array("../Case_1_Worst.txt", 1000);

    // read_array("../Case_2_Best.txt", 10000);
    // read_array("../Case_2_Avg.txt", 10000);
    // read_array("../Case_2_Worst.txt", 10000);

    read_array("../Case_3_Best.txt", 100000);
    read_array("../Case_3_Avg.txt", 100000);
    read_array("../Case_3_Worst.txt", 100000);
}