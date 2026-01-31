#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
} node;
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
void insert(int one ,int two ){

}
void delete(){
}

void  front (){

}
void rear(){

}
void print(){

}
int main(){
insert(12,5);
insert(15,2);
insert(5,7);
print();
front();
rear();
delete();
print();
rear();
insert(7,1);
print();
front();
delete();
print();
rear();
insert(52,3);
delete();
insert(101,6);
print();
    return 0;
}