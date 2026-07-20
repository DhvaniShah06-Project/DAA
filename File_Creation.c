/* creating 3 files 1-1000,1-10000,1-100000 for best,avg,worst
*/

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

void main()
{
    FILE *fp_Case_1_Best, *fp_Case_1_Avg, *fp_Case_1_Worst;
    FILE *fp_Case_2_Best, *fp_Case_2_Avg, *fp_Case_2_Worst;
    FILE *fp_Case_3_Best, *fp_Case_3_Avg, *fp_Case_3_Worst;

    

    fp_Case_1_Best = fopen("Case_1_Best.txt", "w");
    fp_Case_1_Avg = fopen("Case_1_Avg.txt", "w");
    fp_Case_1_Worst = fopen("Case_1_Worst.txt", "w");

    fp_Case_2_Best = fopen("Case_2_Best.txt", "w");
    fp_Case_2_Avg = fopen("Case_2_Avg.txt", "w");
    fp_Case_2_Worst = fopen("Case_2_Worst.txt", "w");

    fp_Case_3_Best = fopen("Case_3_Best.txt", "w");
    fp_Case_3_Avg = fopen("Case_3_Avg.txt", "w");
    fp_Case_3_Worst = fopen("Case_3_Worst.txt", "w");

  
 
    for (int i = 1; i <= 1000; i++)
    {
        fprintf(fp_Case_1_Best, "%d\n", i);
        fprintf(fp_Case_1_Worst, "%d\n", 1000 - i + 1);
        fprintf(fp_Case_1_Avg, "%d\n", (((i * 269) + 513) % 1000) + 1);
    }

    for (int i = 1; i <= 10000; i++)
    {
        fprintf(fp_Case_2_Best, "%d\n", i);
        fprintf(fp_Case_2_Worst, "%d\n", 10000 - i + 1);
        fprintf(fp_Case_2_Avg, "%d\n", (((i * 269) + 513) % 10000) + 1);
    }
    for (int i = 1; i <= 100000; i++)
    {
        fprintf(fp_Case_3_Best, "%d\n", i);
        fprintf(fp_Case_3_Worst, "%d\n", 100000 - i + 1);
        fprintf(fp_Case_3_Avg, "%d\n", (((i * 269) + 513) % 100000) + 1);
    }
}
