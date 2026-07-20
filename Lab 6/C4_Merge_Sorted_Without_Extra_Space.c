/*C Merge Two Sorted Arrays Without Extra Space.
Given two sorted arrays a[] and b[] of size n and m respectively, merge both the arrays and rearrange the elements such that the smallest n
elements are in a[] and the remaining m elements are in b[]. All elements in a[] and b[] should be in sorted order.
Examples:
Input: a[] = [2, 4, 7, 10], b[] = [2, 3] ; Output: a[] = [2, 2, 3, 4], b[] = [7, 10]
Explanation: Combined sorted array = [2, 2, 3, 4, 7, 10], array a[] contains smallest 4 elements: 2, 2, 3 and 4, and array b[] contains remaining 2
elements: 7, 10.
Input: a[] = [1, 5, 9, 10, 15, 20], b[] = [2, 3, 8, 13]; Output: a[] = [1, 2, 3, 5, 8, 9], b[] = [10, 13, 15, 20]
Explanation: Combined sorted array = [1, 2, 3, 5, 8, 9, 10, 13, 15, 20], array a[] contains smallest 6 elements: 1, 2, 3, 5, 8 and 9, and array b[]
contains remaining 4 elements: 10, 13, 15, 20.
Input: a[] = [0, 1], b[] = [2, 3]; Output: a[] = [0, 1], b[] = [2, 3]
Explanation: Combined sorted array = [0, 1, 2, 3], array a[] contains smallest 2 elements: 0 and 1, and array b[] contains remaining 2 elements:
2 and 3.
*/

#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to merge two sorted arrays without extra space
void mergeArraysWithoutSpace(int a[], int n, int b[], int m) {
    int i = n - 1; // Pointer at the end of array a[]
    int j = 0;     // Pointer at the beginning of array b[]

    // Swap elements if an element in a[] is greater than an element in b[]
    while (i >= 0 && j < m) {
        if (a[i] > b[j]) {
            int temp = a[i];
            a[i] = b[j];
            b[j] = temp;
            i--;
            j++;
        } else {
            // Since both arrays are already sorted, if a[i] <= b[j],
            // all remaining elements are in their correct array partitions.
            break;
        }
    }

    // Sort both arrays individually to restore sorted order
    sort(a, n);
    sort(b, m);
}
void printArray(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ,",a[i]);
    }
}

int main() {
    // Example 1
    int a1[] = {2, 4, 7, 10};
    int b1[] = {2, 3};
    int n1 = sizeof(a1) / sizeof(a1[0]);
    int m1 = sizeof(b1) / sizeof(b1[0]);

    printf("Example 1 Before:\na[] = "); printArray(a1, n1);
    printf("b[] = "); printArray(b1, m1);
    mergeArraysWithoutSpace(a1, n1, b1, m1);
    printf("Example 1 After:\na[] = "); printArray(a1, n1);
    printf("b[] = "); printArray(b1, m1);
    printf("\n");

    // Example 2
    int a2[] = {1, 5, 9, 10, 15, 20};
    int b2[] = {2, 3, 8, 13};
    int n2 = sizeof(a2) / sizeof(a2[0]);
    int m2 = sizeof(b2) / sizeof(b2[0]);

    printf("Example 2 Before:\na[] = "); printArray(a2, n2);
    printf("b[] = "); printArray(b2, m2);
    mergeArraysWithoutSpace(a2, n2, b2, m2);
    printf("Example 2 After:\na[] = "); printArray(a2, n2);
    printf("b[] = "); printArray(b2, m2);
    printf("\n");

    return 0;
}
