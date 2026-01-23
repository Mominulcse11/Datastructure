#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
} node;

node *front=NULL;
node *rear=NULL;
node* createnode(int value){
    node *temp = (node *)malloc(sizeof(node));
    //Heap overflow check
    if(temp==NULL){
        printf("Heap overflow\n");
        return NULL;
    }
    temp->data = value;
    temp->next = NULL;
    return temp;
}
void enqueue(int value){
    node *newnode = createnode(value);
    //newnode check
    if(newnode==NULL){
        return;
    }
    //case 1 :Empty queue
    if(front ==NULL)
    {
        front = rear = newnode;
        return;
    }
    // case 2 : NO empty queue
    rear->next = newnode;
    rear=newnode;
}
int dequeue(){
    //queue undeerflow check
    if(front==NULL){
        printf("queue underflow\n");
        return -1;
    }
    node *temp = front;
    int value = temp->data;
    front =temp->next;
    free(temp);
    //case if queue become NULL
    if(front==NULL){
        rear = NULL;
    }
    return value;
}
int peek(){
    //empty check
    if(front==NULL){
        printf("The queue is empty\n");
        return -1;
    }
    return front->data;
}
void print (){
    //empty check
    if(front==NULL){
        printf("The queue is empty\n");
        return;
    }
    node *temp = front;
    printf("Queue : ");
    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp=temp -> next;
        
    }
    printf("NULL\n");
}
int main(){
 enqueue(10);
    enqueue(20);
    enqueue(30);

    print();

    printf("Dequeued: %d\n", dequeue());
    printf("Front element: %d\n", peek());

    print();

    return 0;
}