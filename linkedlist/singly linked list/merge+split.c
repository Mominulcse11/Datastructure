
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} node;

node *head=NULL;
node *tail = NULL;
node *createnode(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("Heap memory exhausted\n");
        return NULL;
    }
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void insertatend(int data) {
    node *t = createnode(data);
    if (t == NULL) return;

    if (head == NULL) {
        head = tail = t; 
        return;
    }
    
    tail->next = t;   
    tail = t;  
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

void freeList() {
    node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){

    insertatend(3);
    insertatend(1);
    insertatend(8);
    insertatend(44);
    insertatend(100);
    insertatend(99);
    insertatend(1003);
    insertatend(2);
    insertatend(999);
    print();

    

    freeList();
    return 0;
}