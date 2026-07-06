#include "stdio.h"
#include "stdlib.h"
#include "math.h"

void main()
{
    FILE *fp_Heap_Case_1_Best, *fp_Heap_Case_1_Avg, *fp_Heap_Case_1_Worst;
    FILE *fp_Heap_Case_2_Best, *fp_Heap_Case_2_Avg, *fp_Heap_Case_2_Worst;
    FILE *fp_Heap_Case_3_Best, *fp_Heap_Case_3_Avg, *fp_Heap_Case_3_Worst;

    fp_Heap_Case_1_Best = fopen("Heap_Case_1_Best.txt", "w");
    fp_Heap_Case_1_Avg = fopen("Heap_Case_1_Avg.txt", "w");
    fp_Heap_Case_1_Worst = fopen("Heap_Case_1_Worst.txt", "w");
    fp_Heap_Case_2_Best = fopen("Heap_Case_2_Best.txt", "w");
    fp_Heap_Case_2_Avg = fopen("Heap_Case_2_Avg.txt", "w");
    fp_Heap_Case_2_Worst = fopen("Heap_Case_2_Worst.txt", "w");
    fp_Heap_Case_3_Best = fopen("Heap_Case_3_Best.txt", "w");
    fp_Heap_Case_3_Avg = fopen("Heap_Case_3_Avg.txt", "w");
    fp_Heap_Case_3_Worst = fopen("Heap_Case_3_Worst.txt", "w");

    for (int i = 1; i <= 1000; i++)
    {
        fprintf(fp_Heap_Case_1_Best, "%d\n", i);
        fprintf(fp_Heap_Case_1_Avg, "%d\n", (((i * 269) + 513) % 1000) + 1);
        fprintf(fp_Heap_Case_1_Worst, "%d\n", (1000 - i + 1));
    }

    for (int i = 1; i <= 10000; i++)
    {
        fprintf(fp_Heap_Case_2_Best, "%d\n", i);
        fprintf(fp_Heap_Case_2_Avg, "%d\n", (((i * 269) + 513) % 10000) + 1);
        fprintf(fp_Heap_Case_2_Worst, "%d\n", (10000 - i + 1));
    }
    for(int i =1;i<=100000;i++){
        fprintf(fp_Heap_Case_3_Best, "%d\n", i);
        fprintf(fp_Heap_Case_3_Avg, "%d\n", (((i * 269) + 513) % 100000) + 1);
        fprintf(fp_Heap_Case_3_Worst, "%d\n", (100000 - i + 1));
    }
    fclose(fp_Heap_Case_1_Best);
    fclose(fp_Heap_Case_1_Avg);
    fclose(fp_Heap_Case_1_Worst);
    fclose(fp_Heap_Case_2_Best);
    fclose(fp_Heap_Case_2_Avg);
    fclose(fp_Heap_Case_2_Worst);
    fclose(fp_Heap_Case_3_Best);
    fclose(fp_Heap_Case_3_Avg);
    fclose(fp_Heap_Case_3_Worst);
}