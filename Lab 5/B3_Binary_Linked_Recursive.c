// B Write a program to implement binary search algorithm using linked list and recursive method.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *createnode(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->link = NULL;
    return newnode;
}

struct Node* read_List(const char *fileName,int *node_count){
    FILE *fp = fopen(fileName, "r");
    struct Node *head = NULL;
    struct Node *tail = NULL;
    *node_count = 0;
    int val;
    while(fscanf(fp,"%d",&val) ==1){
        struct Node* newNode = createnode(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        } else {
            tail->link = newNode;
            tail = newNode;
        }
        (*node_count)++;
    }
    fclose(fp);
    return head;
}

struct Node *findMiddle(struct Node *head, struct Node *end)
{
    struct Node *slow = head;
    struct Node *fast = head;
    while (fast != end && fast->link != end)
    {
        slow = slow->link;
        fast = fast->link->link;
    }
    return slow;
}

struct Node *binary_Search(struct Node *start, struct Node *end, int search)
{
    if (start == end)
        return NULL;
    struct Node *mid = findMiddle(start, end);
    if (mid == NULL)
        return NULL;
    if (mid->data == search)
        return mid;
    else if (mid->data < search)
        return binary_Search(mid->link, end, search);
    else
        return binary_Search(start, mid, search);
}

int main(){
    int search,total_nodes=0;
    printf("Enter the number to search: ");
    scanf("%d",&search);
    clock_t start_time = clock();
    struct Node *head = read_List("../Case_3_Best.txt",&total_nodes);

    struct Node* result = binary_Search(head,NULL,search);
    if(result != NULL){
        printf("Element %d found in the list.\n",search);
    } else {
        printf("Element %d not found in the list.\n",search);
    }
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);

}