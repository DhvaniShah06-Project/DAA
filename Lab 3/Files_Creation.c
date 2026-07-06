/* creating 27 files as:
Bubble Sort :
1-1000 best,avg,worst
1-10000 best,avg,worst
1-100000 best avg worst

Insertion Sort
1-1000 best,avg,worst
1-10000 best,avg,worst
1-100000 best avg worst

Selection_Sort
1-1000 best,avg,worst
1-10000 best,avg,worst
1-100000 best avg worst
*/

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

void main()
{
    FILE *fp_Bubble_Case_1_Best, *fp_Bubble_Case_1_Avg, *fp_Bubble_Case_1_Worst;
    FILE *fp_Bubble_Case_2_Best, *fp_Bubble_Case_2_Avg, *fp_Bubble_Case_2_Worst;
    FILE *fp_Bubble_Case_3_Best, *fp_Bubble_Case_3_Avg, *fp_Bubble_Case_3_Worst;

    FILE *fp_Insertion_Sort_Case_1_Best, *fp_Insertion_Sort_Case_1_Avg, *fp_Insertion_Sort_Case_1_Worst;
    FILE *fp_Insertion_Sort_Case_2_Best, *fp_Insertion_Sort_Case_2_Avg, *fp_Insertion_Sort_Case_2_Worst;
    FILE *fp_Insertion_Sort_Case_3_Best, *fp_Insertion_Sort_Case_3_Avg, *fp_Insertion_Sort_Case_3_Worst;

    FILE *fp_Selection_Sort_Case_1_Best, *fp_Selection_Sort_Case_1_Avg, *fp_Selection_Sort_Case_1_Worst;
    FILE *fp_Selection_Sort_Case_2_Best, *fp_Selection_Sort_Case_2_Avg, *fp_Selection_Sort_Case_2_Worst;
    FILE *fp_Selection_Sort_Case_3_Best, *fp_Selection_Sort_Case_3_Avg, *fp_Selection_Sort_Case_3_Worst;

    fp_Bubble_Case_1_Best = fopen("Bubble_Case_1_Best.txt", "w");
    fp_Bubble_Case_1_Avg = fopen("Bubble_Case_1_Avg.txt", "w");
    fp_Bubble_Case_1_Worst = fopen("Bubble_Case_1_Worst.txt", "w");

    fp_Bubble_Case_2_Best = fopen("Bubble_Case_2_Best.txt", "w");
    fp_Bubble_Case_2_Avg = fopen("Bubble_Case_2_Avg.txt", "w");
    fp_Bubble_Case_2_Worst = fopen("Bubble_Case_2_Worst.txt", "w");

    fp_Bubble_Case_3_Best = fopen("Bubble_Case_3_Best.txt", "w");
    fp_Bubble_Case_3_Avg = fopen("Bubble_Case_3_Avg.txt", "w");
    fp_Bubble_Case_3_Worst = fopen("Bubble_Case_3_Worst.txt", "w");

    fp_Selection_Sort_Case_1_Best = fopen("Selection_Sort_Case_1_Best.txt", "w");
    fp_Selection_Sort_Case_1_Avg = fopen("Selection_Sort_Case_1_Avg.txt", "w");
    fp_Selection_Sort_Case_1_Worst = fopen("Selection_Sort_Case_1_Worst.txt", "w");

    fp_Selection_Sort_Case_2_Best = fopen("Selection_Sort_Case_2_Best.txt", "w");
    fp_Selection_Sort_Case_2_Avg = fopen("Selection_Sort_Case_2_Avg.txt", "w");
    fp_Selection_Sort_Case_2_Worst = fopen("Selection_Sort_Case_2_Worst.txt", "w");

    fp_Selection_Sort_Case_3_Best = fopen("Selection_Sort_Case_3_Best.txt", "w");
    fp_Selection_Sort_Case_3_Avg = fopen("Selection_Sort_Case_3_Avg.txt", "w");
    fp_Selection_Sort_Case_3_Worst = fopen("Selection_Sort_Case_3_Worst.txt", "w");

    fp_Insertion_Sort_Case_1_Best = fopen("Insertion_Sort_Case_1_Best.txt", "w");
    fp_Insertion_Sort_Case_1_Avg = fopen("Insertion_Sort_Case_1_Avg.txt", "w");
    fp_Insertion_Sort_Case_1_Worst = fopen("Insertion_Sort_Case_1_Worst.txt", "w");

    fp_Insertion_Sort_Case_2_Best = fopen("Insertion_Sort_Case_2_Best.txt", "w");
    fp_Insertion_Sort_Case_2_Avg = fopen("Insertion_Sort_Case_2_Avg.txt", "w");
    fp_Insertion_Sort_Case_2_Worst = fopen("Insertion_Sort_Case_2_Worst.txt", "w");

    fp_Insertion_Sort_Case_3_Best = fopen("Insertion_Sort_Case_3_Best.txt", "w");
    fp_Insertion_Sort_Case_3_Avg = fopen("Insertion_Sort_Case_3_Avg.txt", "w");
    fp_Insertion_Sort_Case_3_Worst = fopen("Insertion_Sort_Case_3_Worst.txt", "w");

    for (int i = 1; i <= 1000; i++)
    {
        fprintf(fp_Bubble_Case_1_Best, "%d\n", i);
        fprintf(fp_Insertion_Sort_Case_1_Best, "%d\n", i);
        fprintf(fp_Selection_Sort_Case_1_Best, "%d\n", i);

        fprintf(fp_Bubble_Case_1_Worst, "%d\n", 1000 - i + 1);
        fprintf(fp_Insertion_Sort_Case_1_Worst, "%d\n", 1000 - i + 1);
        fprintf(fp_Selection_Sort_Case_1_Worst, "%d\n", 1000 - i + 1);

        fprintf(fp_Bubble_Case_1_Avg, "%d\n", (((i * 269) + 513) % 1000) + 1);
        fprintf(fp_Insertion_Sort_Case_1_Avg, "%d\n", (((i * 269) + 513) % 1000) + 1);
        fprintf(fp_Selection_Sort_Case_1_Avg, "%d\n", (((i * 269) + 513) % 1000) + 1);
    }

    for (int i = 1; i <= 10000; i++)
    {
        fprintf(fp_Bubble_Case_2_Best, "%d\n", i);
        fprintf(fp_Insertion_Sort_Case_2_Best, "%d\n", i);
        fprintf(fp_Selection_Sort_Case_2_Best, "%d\n", i);

        fprintf(fp_Bubble_Case_2_Worst, "%d\n", 10000 - i + 1);
        fprintf(fp_Insertion_Sort_Case_2_Worst, "%d\n", 10000 - i + 1);
        fprintf(fp_Selection_Sort_Case_2_Worst, "%d\n", 10000 - i + 1);

        fprintf(fp_Bubble_Case_2_Avg, "%d\n", (((i * 269) + 513) % 10000) + 1);
        fprintf(fp_Insertion_Sort_Case_2_Avg, "%d\n", (((i * 269) + 513) % 10000) + 1);
        fprintf(fp_Selection_Sort_Case_2_Avg, "%d\n", (((i * 269) + 513) % 10000) + 1);
    }
    for (int i = 1; i <= 100000; i++)
    {
        fprintf(fp_Bubble_Case_3_Best, "%d\n", i);
        fprintf(fp_Insertion_Sort_Case_3_Best, "%d\n", i);
        fprintf(fp_Selection_Sort_Case_3_Best, "%d\n", i);

        fprintf(fp_Bubble_Case_3_Worst, "%d\n", 100000 - i + 1);
        fprintf(fp_Insertion_Sort_Case_3_Worst, "%d\n", 100000 - i + 1);
        fprintf(fp_Selection_Sort_Case_3_Worst, "%d\n", 100000 - i + 1);

        fprintf(fp_Bubble_Case_3_Avg, "%d\n", (((i * 269) + 513) % 100000) + 1);
        fprintf(fp_Insertion_Sort_Case_3_Avg, "%d\n", (((i * 269) + 513) % 100000) + 1);
        fprintf(fp_Selection_Sort_Case_3_Avg, "%d\n", (((i * 269) + 513) % 100000) + 1);
    }
}
