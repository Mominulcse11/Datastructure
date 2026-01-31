#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data, priority;
    struct Node *next;
} node;

node *head = NULL;

node* createnode (int data,int priority){
    node *temp = (node *)malloc(sizeof(node));
    if(temp==NULL){
        printf("Heap overflow!Memory not available\n");
        return NULL;
    }
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;
    return temp;
}
 //Enqueue based on priority
void enqueue(int data,int priority){
    node *temp = createnode(data,priority);
    if(temp==NULL){
        return;
    }
    // case 1:Empty Queue
    if(head ==NULL){
        head = temp;
        return;
    }

    //case 2: Higher priority than head
    if(priority<head->priority){
        temp->next = head;
        head = temp;
        return;
    }
    
    //case 3:Insert in middle or end for priority
    node *current = head;
    while(current->next!=NULL&& current->next->priority <=priority){

        current = current->next;
    }

    temp->next = current->next;
    current->next = temp;
}
//Dequeue highest priority element
int dequeue(){
    if(head ==NULL){
        printf(" Queue underflow!Queue is empty \n");
        return -1;
    }
    node *temp = head;
    int value = temp->data;
    head = head->next;
    free(temp);
    return value;
}
 void front (){
    if(head==NULL){
        printf("Queue is empty.\n");
        return ;
    }
    printf("Front Element: %d\n", head->data);  
}
void rear(){
    if(head==NULL){
        printf("Queue is empty.\n");
        return ;
    }
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("Rear Element: %d\n", temp->data);  
}
void print (){
    //empty check
    if(head==NULL){
        printf("The queue is empty\n");
        return;
    }
    node *temp = head;
    printf("Queue : ");
    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp=temp -> next;
        
    }
    printf("NULL\n");
}
int main(){

    enqueue(10, 3);
    enqueue(20, 1);
    enqueue(30, 2);
    enqueue(40, 0);

    print();

    printf("\nDequeued: %d\n", dequeue());
    front();
    rear();


    print();

    return 0;
}

/*
 Error Handling Cheat Sheet (EXAM GOLD)
🔹 createNode()

✔ malloc failure → Heap overflow

🔹 enqueue()

✔ New node NULL → stop
✔ Empty queue case
✔ Insert at front
✔ Insert in middle
✔ Insert at end

🔹 dequeue()

✔ Empty queue → Underflow
✔ Proper memory free

🔹 peek()

✔ Empty queue check

🔹 display()

✔ Empty queue handling
*/