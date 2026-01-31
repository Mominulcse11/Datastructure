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

//return the middle node.If there are two middle nodes, return the second middle node.


 node* findmid(){
       int q=0,t=0;
    node* temp=head;

  while(temp!=NULL){
    q++;
    temp=temp->next;
  }

temp=head;
    while(t!=(q/2)){
        t++;
        temp=temp->next;
    }

  return temp;

  /* two pointer solution 
  node* middleNode(node* head) {

  
    node* slow = head;

    node* fast = head;

    // Move fast pointer 2 steps and slow pointer 1 step
    // Check fast != NULL (for even list end) and fast->next != NULL (for odd list end)

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;       // 1 step
        fast = fast->next->next; // 2 steps
    }

    return slow;
}*/

 }

 
node* deleteMiddle() {
    int q=0,t=0;
   node*temp=head;
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    while(temp!=NULL){
        q++;
        temp=temp->next;
    }
    temp=head;
    while(t<(q/2)-1){
        t++;
        temp=temp->next;
    }
        node *temp1=temp->next;
        temp->next=temp1->next;
      
    free(temp1);
return head;

}

 int main(){

    insertatend(3);
    insertatend(1);
    insertatend(7);
    insertatend(6);
    insertatend(2);
    insertatend(9);

    print();
    node *temp = findmid();
    printf("Middle node of Linked List is : %d", temp->data);
    node *todelete = deleteMiddle();
    printf("After deleting the middle the linked list is : \n");
    print();

    return 0;
 }
