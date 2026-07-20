/*B Move all Zeros to End of Array.
Given an array of integers arr[], move all the zeros to the end of the array while maintaining the relative order of all non-zero elements.
Examples:
Input: arr[] = [1, 2, 0, 4, 3, 0, 5, 0]; Output: [1, 2, 4, 3, 5, 0, 0, 0]
Explanation: There are three 0s that are moved to the end.
Input: arr[] = [10, 20, 30]; Output: [10, 20, 30]
Explanation: No change in array as there are no 0s.
Input: arr[] = [0, 0]; Output: [0, 0]
Explanation: No change in array as there are all 0s*/

#include <stdio.h>

void moveZerosToEnd(int arr[], int n) {
    int count = 0;

    
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            int temp = arr[i];
            arr[i] = arr[count];
            arr[count] = temp;
            
            count++; 
        }
    }
}


void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    
    int arr1[] = {1, 2, 0, 4, 3, 0, 5, 0};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Input 1:  "); printArray(arr1, n1);
    moveZerosToEnd(arr1, n1);
    printf("Output 1: "); printArray(arr1, n1);
    printf("\n");

    
    int arr2[] = {10, 20, 30};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Input 2:  "); printArray(arr2, n2);
    moveZerosToEnd(arr2, n2);
    printf("Output 2: "); printArray(arr2, n2);
    printf("\n");

    
    int arr3[] = {0, 0};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("Input 3:  "); printArray(arr3, n3);
    moveZerosToEnd(arr3, n3);
    printf("Output 3: "); printArray(arr3, n3);

    return 0;
}
