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
    if(temp == NULL){
        printf("Stack overflow (Heap Full)\n");
        return;
    }
    temp->next = head;
    head = temp;
}

/* POP */
int pop(){
    if(head == NULL){
        printf("Stack underflow!\n");
        return -1;
    }
    node *temp = head;
    int value = temp->data;
    head = temp->next;
    free(temp);
    return value;
}

/* TOP */
int top(){
    if(head == NULL){
        printf("Stack underflow!\n");
        return -1;
    }
    return head->data;
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

    print();

    printf("Popped: %d\n", pop());
    printf("Top: %d\n", top());

    print();
    return 0;
}
