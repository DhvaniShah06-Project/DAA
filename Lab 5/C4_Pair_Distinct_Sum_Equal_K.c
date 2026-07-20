/*C Given the root of a Binary Search Tree (BST) of size n and an integer target, determine whether there exists a pair
of distinct nodes in the BST such that the sum of their values is equal to the given target using in order traversal.
Return true if such a pair exists; otherwise, return false.
Example:
Input: root = [7, 3, 8, 2, 4, N, 9], target = 12
Output: true
Explanation: In the given binary tree, there are two nodes (3 and 9) that add up to 12*/

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "stdbool.h"

struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;
};

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = value;
    newNode->lptr = newNode->rptr = NULL;
    return newNode;
}
struct node *insert(struct node *root, int value)
{
    if (root == NULL)
        return createNode(value);
    if (value < root->info)
        root->lptr = insert(root->lptr, value);
    else if (value > root->info)
        root->rptr = insert(root->rptr, value);
    return root;
};

void inOrder(struct node *root, int arr[], int *index)
{
    if (root == NULL)
        return;
    inOrder(root->lptr, arr, index);
    arr[*index] = root->info;
    (*index)++;
    inOrder(root->rptr, arr, index);
}

bool findSum(int arr[], int size, int target)
{
    int left = 0, right = size - 1;
    while (left < right)
    {
        int currentSum = arr[left] + arr[right];
        if (currentSum == target)
        {
            printf("%d + %d = %d\n", arr[left], arr[right], target);
            return true;
        }
        else if (currentSum < target)
            left++;
        else
            right--;
    }
    return false;
}

int main()
{
    struct node *root = NULL;
    char fileName[] = "../Case_3_Worst.txt";
    int value, target, nodeCount = 0;
    clock_t start_time, end_time;
    double cpu_time_used;

    FILE *file = fopen(fileName, "r");
    if (file == NULL)
        return 1;

    while (fscanf(file, "%d", &value) != EOF)
    {
        root = insert(root, value);
        nodeCount++;
    }
    fclose(file);

    int *arr = (int *)malloc(nodeCount * sizeof(int));
    int index = 0;
    printf("Enter target Sum : ");
    scanf("%d", &target);

    start_time = clock();

    inOrder(root, arr, &index);
    bool found = findSum(arr, nodeCount, target);
    end_time = clock();

    if (found)
        printf("Output : True\n");
    else
        printf("Output : False\n");

    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("%-25s | Size: %-7d | CPU Time: %.6f seconds\n", fileName, nodeCount, cpu_time_used);
    free(arr);
    return 0;
}