#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
} node;

node *head= NULL,*tail=NULL;

node *createnode (int data){
    node *temp = (node *)malloc(sizeof(node));
    if(temp == NULL){
        printf("Heap overflow!Memory allocation failed.\n");
        return NULL;
    }
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void insert(int value){
    node *temp = createnode(value);
    if(temp==NULL){
     printf("Heap overflow\n");
     return;
    }
    if(head==NULL){
        head =tail= temp;
        printf("%d -> Inserted at end \n", value);
        return;
    }
    tail->next = temp;
    temp->prev = tail;
    tail=temp;
    printf("%d -> Inserted at end\n", value);
}

void print(){
    if(head==NULL){
        printf("Nothing to Print! \n");
        return;
    }
    node *temp = head;
     printf("Linked List : NULL<-> ");
    while (temp != NULL){
            printf("%d <-> ", temp->data);
            temp = temp->next;
    }
    printf("NULL\n");
}

void deleteatindex(int k){
    if(head==NULL) {
        printf("Empty List!\n");
        return;
    }
    if(k<0){
        printf("Invalid position!\n");
        return;
    }
    node *temp = head;
    for (int i = 0; i < k;i++){
        temp = temp->next;
    }
    if(temp==NULL){
        printf("Invalid position!\n");
        return;
    }
    /* Case 1: Only one node */
    if (head == tail) {
        head = tail = NULL;
    }
    /* Case 2: Deleting head */
    else if (temp == head) {
        head = head->next;
        head->prev = NULL;
    }
    /* Case 3: Deleting tail */
    else if (temp == tail) {
        tail = tail->prev;
        tail->next = NULL;
    }
    /* Case 4: Deleting middle node */
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    printf("Deleted node at position %d\n", k);
    free(temp);
}

int main(){

    insert(3);
    insert(1);
    insert(8);
    insert(44);
    insert(100);
    insert(99);
    insert(1003);
    insert(2);
    insert(999);
    print();
    deleteatindex(5);
    print();

    return 0;
}