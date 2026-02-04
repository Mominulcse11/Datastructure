#include<stdio.h>
#define capacity 100

int queue[capacity];

int front = -1;
int rear = -1;

void enqueue(int data){
    if(front==-1){
        front = rear = 0;
        queue[rear] = data;
        printf("Inserted element -> %d \n" ,data);
    }
    else if(rear+1<capacity){
        rear++;
        queue[rear] = data;
        printf("Inserted element -> %d \n" ,data);
    }
    else{
        printf("Full Queue\n");
    }
}

void dequeue(){
    //empty 
    if(front==-1 && rear==-1){
        printf("Empty queue!\n");
    }
    //one element
    else if(front >=0 && rear==front ){
        printf("Deleted element -> %d \n" ,queue[front]);
        rear = front = -1;
    }
    else{
          printf("Deleted element -> %d \n" ,queue[front++]);// it prints the element at the FRONT index and then increments FRONT using FRONT++ to move the front of the queue to the next element.
    }
}
void frontel(){
    if(front>=0){
        printf("Front -> %d\n",  queue[front]);
    }
    else{
        printf("Empty Queue\n");
    }
}
void rearel(){
    if(rear<capacity && rear>=0){
        printf("Rear -> %d\n", queue[rear]);
    }
    else{
        printf("Empty Queue\n");
    }
}

void print(){
    printf("Queue :");
    for (int i = front; i <= rear;i++){
        printf("%d ->", queue[i]);
    }
    printf("NULL\n");
}

void main()
{
enqueue(12);
enqueue(15);
enqueue(5);
print();
frontel();
rearel();
dequeue();
print();
rearel();
enqueue(7);
print();
frontel();
dequeue();
print();
rearel();
 enqueue(52);
dequeue();
enqueue(101);
print();
}