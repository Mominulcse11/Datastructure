#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} node;

node *head=NULL;
 node * createnode(int data){
     node *temp = (node *)malloc(sizeof(node));
     if(temp==NULL){
         printf("Heap memory exhausted\n");
         return NULL;
     }
     temp->data = data;
     temp->next = NULL;
     return temp;
 }

void insertatend(int data){
    node *t = createnode(data);
    if(t==NULL) return;

    if(head==NULL){
        head = t;
        return;
    }
    node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = t;
}

void print (){
    if(head==NULL){
        printf("The list is empty!\n");
        return;
    }
    printf("The liked list is : ");

    node *temp = head;
    while(temp!=NULL){
        printf(" %d ->", temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");
}
//merge -> middlenode -> mergesort   ai priority te dibo system error na pete 
node* merge(node* a, node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    node* result = NULL;

    if (a->data <= b->data) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}
 node* getMiddle(node* head) {
    node* slow = head;
    node* fast = head->next;

    while(fast ->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
node* mergeSort(node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    node* mid = getMiddle(head);
    node* secondHalf = mid->next;
    mid->next = NULL;

    node* left = mergeSort(head);
    node* right = mergeSort(secondHalf);

    return merge(left, right);
}
int check_sorted(){
    node *temp = head;
    while(temp->next!=NULL){
        if(temp->data > temp->next->data){
            return 0;
        }
        temp = temp->next;
    }
    return 1;
}




int main(){

    insertatend(3);
    insertatend(1);
    insertatend(7);
    insertatend(6);
    insertatend(2);
    insertatend(9);


    print();
    if(check_sorted()==1){
        printf("The list is sorted!\n");
    }
    else  printf("The list is not sorted!\n");

    head=mergeSort(head);
    printf("Ater Merge Sort : ");
    print();
    if(check_sorted()==1){
        printf("The list is sorted!\n");
    }
    else  printf("The list is not sorted!\n");

    return 0;
}