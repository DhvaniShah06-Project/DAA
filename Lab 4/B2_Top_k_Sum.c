/*Given two integer arrays a[] and b[] of the same length, and an positive integer k, the goal is to find the top k maximum sum combinations,
where each combination is formed by adding one element from a and one from b using heap sort. Each index from both arrays can be used at
most once in a pair. Return the k largest sums in descending order.
Examples:
Input: a[] = [3, 2], b[] = [1, 4], k = 2
Output: [7, 6]
Explanation: Possible sums: 3 + 1 = 4, 3 + 4 = 7, 2 + 1 = 3, 2 + 4 = 6, Top 2 sums are 7 and 6.
Input: a[] = [1, 4, 2, 3], b[] = [2, 5, 1, 6], k = 3
Output: [10, 9, 9]
Explanation: The top 3 maximum possible sums are : 4 + 6 = 10, 3 + 6 = 9, and 4 + 5 = 9.*/

#include <stdio.h>
void min_Heapify(int arr[], int n, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] < arr[smallest])
        smallest = l;
    if (r < n && arr[r] < arr[smallest])
        smallest = r;
    if (smallest != i)
    {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        min_Heapify(arr, n, smallest);
    }
}

void main()
{
    int size, k = 0, max_no;
    printf("Enter size : ");
    scanf("%d", &size);
    int a[size], b[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter Elements of Array A : ");
        scanf("%d", &a[i]);
        printf("Enter Elements of Array B : ");
        scanf("%d", &b[i]);
    }
    printf("Enter value of k : ");
    scanf("%d", &max_no);
    int total_size = size * size;
    int output[total_size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int sum = a[i] + b[j];
            output[k++] = sum;
        }
    }
    for (int i = total_size / 2 - 1; i >= 0; i--)
    {
        min_Heapify(output, total_size, i);
    }
    for (int i = total_size - 1; i > 0; i--)
    {
        int temp = output[0];
        output[0] = output[i];
        output[i] = temp;
        min_Heapify(output, i, 0);
    }
    printf("Top %d maximum sums are : ", max_no);
    for (int i = 0; i < max_no; i++)
    {
        printf("%d -> ", output[i]);
    }
    printf("Over");
}