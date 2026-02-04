


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
void reverse(){
    if (head == NULL || head->next == NULL) {
        return; 
    }

    node *lokey = head;
    node  *rrr=NULL;
    while(lokey!=NULL){
        //swap ->prev and ->next
        rrr = lokey->prev;
        lokey->prev = lokey->next;
        lokey->next = rrr;

        lokey = lokey->prev;
    }
    if(rrr!=NULL){
        head = rrr->prev;
    }
    



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
    reverse();
    print();

    return 0;
}