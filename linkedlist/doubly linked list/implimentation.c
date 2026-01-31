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
void delete(int value){
    int flag = 0;
    if(head==NULL){
        printf("Empty list!\n");
        return;
    }
    if(  head==tail && head->data==value ){
        free(head);
        head = tail = NULL;
        printf("%d -> Deleted\n", value);
        return;
    }
    node *cur = head;
    while(cur!=NULL){
        if(cur->data==value){
            if(cur==head){
                 head = head->next;
                 head->prev = NULL;
            }
            else if(cur==tail){
                tail = tail->prev;
                tail->next = NULL;
            }
            else{
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;            
            }
            free(cur);
            flag = 1;
            break;
        }
        cur = cur->next;
    }
     if(flag==1){
            printf("%d -> Deleted!\n",value);
    }
    else{
        printf("%d  Not Found!\n",value);
    }
}
void search(int value){
    int flag = 0;
    if(head==NULL){
        printf("Empty List!\n");
        return;
    }
    node *temp = head;
    while(temp!=NULL){
        if(temp->data==value){
            flag=1;//forward e treverse e temp=temp->next   backward e treverse  e temp=temp->prev
        }
        temp = temp->next;
    }
     if(flag){
    printf("%d -> Found!\n",value);  
     }
   else{
     printf("%d -> Not Found!\n",value);
   }
}
void print_forward(){
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
void print_backward(){
    if(head==NULL){
        printf("Nothing to Print! \n");
        return;
    }
    node *temp = tail;
     printf("Linked List : NULL<-> ");
    while (temp != NULL){
            printf("%d <-> ", temp->data);
            temp = temp->prev;
    }
    printf("NULL\n");
}
void main()
{
    print_forward();
    print_backward();
    delete(2023);
    search(1971);
    insert(5);
    insert(15);
    print_forward();
    print_backward();
    insert(56);
    insert(25);
    print_forward();
    print_backward();
    search(1952);
    delete(15);
    print_forward();
    print_backward();
    delete(404);
    print_forward();
    print_backward();
    insert(100);
    print_forward();
    print_backward();
    search(100);
    print_forward();
    print_backward();
    delete(5);
    print_forward();
    print_backward();
    delete(100);
    print_forward();
    print_backward();
}
