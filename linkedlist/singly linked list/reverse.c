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

void reverseList() {
    
    if (head == NULL || head->next == NULL) {
        return; 
    }
    node* prev , *current,*next;
    current=head;
    prev=NULL;
    while(current!=NULL){
        next=current->next;
        current ->next=prev;
        prev=current ;
        current=next;
    }
    head= prev;
}
void reverselistrecursion(node* temp){
    /*node *temp = head;মারাত্মক লজিক ভুল (node *temp = head): আপনি ফাংশনের শুরুতে temp = head লিখেছেন। 
    রিকারশন যখন নিজেকে কল করবে, তখন প্রতিবার সে আবার লিস্টের শুরু (head) থেকে কাজ শুরু করবে।
     সে কখনোই পরের নোডে যেতে পারবে না।
সমাধান: ফাংশনের প্যারামিটার হিসেবে নোড পাস করতে হবে।*/
    if(temp->next==NULL){
        head = temp;
        return;
    }
    reverselistrecursion(temp->next);
    node *temp1 = temp->next;//temp1 holo 9 .ar temp holo 2   in  3 -> 1 -> 7 -> 6 -> 2 -> 9 -> NULL
    temp1->next = temp;
    temp->next = NULL;
}


int main(){

    insertatend(3);
    insertatend(1);
    insertatend(7);
    insertatend(6);
    insertatend(2);
    insertatend(9);

    print();
    reverseList();
    printf("AFTER REVERSE THE LIST: ");
    print();
    reverselistrecursion(head);//aikhane head  dite bhule gesilam
    printf("AFTER REVERSE THE LIST: ");
    print();
    return 0;
}