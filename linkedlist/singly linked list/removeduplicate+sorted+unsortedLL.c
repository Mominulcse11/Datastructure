#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

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


void deleteDuplicatesSorted() {
    if (head == NULL) return;

    node *current = head;
    while (current->next != NULL) {
        if (current->data == current->next->data) {
            node *temp = current->next;
            current->next = temp->next;
            
            
            if (temp == tail) {
                tail = current;
            }
            
            free(temp);
            
        } else {
            current = current->next;
        }
    }
}
void deleteDuplicatesUnsorted() {
    if (head == NULL) return;

    node *ptr1 = head;
    node *ptr2, *dup;

    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
        
        
        while (ptr2->next != NULL) {
            if (ptr1->data == ptr2->next->data) {
                dup = ptr2->next;
                ptr2->next = dup->next;
                
                if (dup == tail) tail = ptr2; 
                
                free(dup);
            } else {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}
void freeList() {
    node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    tail = NULL; 
}

int main(){

    insertatend(3);
    insertatend(1);
    insertatend(3);
    insertatend(5);
    insertatend(999);
    insertatend(100);

    insertatend(44);
    insertatend(100);
    insertatend(99);
    insertatend(1003);
    insertatend(2);
    insertatend(999);
    print();
    printf("Before deletion:\n");
    print();

    deleteDuplicatesUnsorted();

    printf("After deleting duplicates:\n");
    print();
    freeList();

    return 0;
}