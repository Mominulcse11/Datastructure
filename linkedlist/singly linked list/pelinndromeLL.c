#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} node;

node *head=NULL;
 node * createnode(int data){
     node *temp = (node *)malloc(sizeof(node));
     if(temp==NULL){
         printf("Heap memory exhausted\n");
         return NULL;
     }
     temp->data = data;
     temp->next = NULL;
     return temp;
 }

void insertatend(int data){
    node *t = createnode(data);
    if(t==NULL) return;

    if(head==NULL){
        head = t;
        return;
    }
    node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = t;
}

void print (){
    if(head==NULL){
        printf("The list is empty!\n");
        return;
    }
    printf("The liked list is : ");

    node *temp = head;
    while(temp!=NULL){
        printf(" %d ->", temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");
}
  node* reverseList(node* head) {
    node* prev , *current,*next;
    current=head;
    prev=NULL;
    while(current!=NULL){
        next=current->next;
        current ->next=prev;
        prev=current ;
        current=next;
    }
    return prev;
}

/*
--------------------------------
Case	       |  Result
---------------|----------------
Empty list	   |  Palindrome
Single node	   |  Palindrome
Two nodes	   |  Compare both
Odd length	   |  Ignore middle
Even length	   |  Direct compare
*/

int ispalindromell(node *head){

      if(head==NULL || head->next==NULL){
          return 1;
      }

      //finding middle element -\(@^0^@)/
      node *slow = head, *fast = head;
 while(fast ->next!=NULL && fast->next->next!=NULL){  //even er jonne fast!=NULL ar odd er jonne  fast->next!=NULL
          slow = slow->next;
          fast = fast->next->next;
      }

      //reverse second half
      node *secondhalf = reverseList(slow->next);
      node *firsthalf = head;

      //compare
      node *temp = secondhalf;
      while(temp!=NULL){
        if(temp->data!=firsthalf->data){
            return 0;
        }
        firsthalf = firsthalf->next;
        temp = temp->next;
      }
      return 1;
}

int main(){

    insertatend(3);
    insertatend(1);
   

    print();

    int pro = ispalindromell(head);
    if(pro){
        printf(" PALINDROME\n");
    }
    else{
                printf("  NOT PALINDROME\n");

    }
 
    return 0;
}