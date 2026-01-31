#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} node;

node *head = NULL;

node* createnode(int value){
    node *temp = (node *)malloc(sizeof(node));
    if(temp == NULL)
        return NULL;

    temp->data = value;
    temp->next = NULL;
    return temp;
}

/* PUSH */
void push(int value){
    node *temp = createnode(value);
    if(temp==NULL){
       printf("Heap overflow\n");
       return;
    }
    if(head==NULL){
        head = temp;
        printf("%d ->Pushed\n", value);
        return;
    }
    temp->next = head;
    head = temp;
    printf("%d ->Pushed\n", value);
}

/* POP */
void  pop(){
    if(head == NULL){
        printf("Empty Stack!\n");
        return ;
    }
    node *temp = head;
    printf("%d ->POPPED\n", temp->data);
    head = temp->next;
    free(temp);

}
/* TOP */
void top(){
    if(head == NULL){
        printf("Empty stack!\n");
        return ;
    }
    printf("Top: %d\n", head->data);
}

/* PRINT */
void print(){
    if(head == NULL){
        printf("Stack is empty\n");
        return;
    }

    node *temp = head;
    printf("Stack: ");
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    push(10);
    push(20);
    push(30);
    pop();
    print();
    print();
    return 0;
}
