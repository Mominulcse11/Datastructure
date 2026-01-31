#include<stdio.h>
#define capacity 100

int stack[capacity];
int top = -1;

void push (int data){
    if(top+1<capacity){
        ++top;
        stack[top] = data;
        printf("Pushed  element -> %d \n", data);
    }
    else{
        printf("Full stack!\n");
    }
}
void pop(){
    if(top>=0){
        printf("Popped  element -> %d\n ", stack[top]);
        top--;
    }
    else{
        printf("Full stack!\n");
    }
}
void Stacktop(){
    if(top>=0){
        printf("TOP  element -> %d\n ", stack[top]);
    }
    else{
        printf("Full stack!\n");
    }
}
void print(){
    printf("Stack : ");
    for (int i = top ; i> 0 ; i--){
         printf("%d -> ", stack[i]);
    }
    printf("NULL\n");
}
void main()
{
push(12);
push(15);
push(5);
print();
Stacktop();
pop();
print();
Stacktop();
push(7);
print();
Stacktop();
pop();
print();
Stacktop();
push(52);
push(101);
print();
}



