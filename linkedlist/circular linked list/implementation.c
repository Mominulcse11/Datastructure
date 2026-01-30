#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
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
    temp->data = data;
    temp->next = NULL;
    return temp;
}
/*
                                                          [10] -> [20] -> [30] (Head: 10, Tail: 30)
           Insert Front (5),
১. ৫-এর next হবে ১০।
২. head বদলে ৫ হয়ে যাবে।  
৩. ৩০-এর next (tail next) এখন ৫-কে পয়েন্ট করবে।,        [5] -> [10] -> [20] -> [30] -> (back to 5)

            Insert End (40),
১. ৩০-এর next হবে ৪০।  
২. ৪০-এর next হবে ১০ (head)।  
৩. tail বদলে ৪০ হয়ে যাবে।,                                [10] -> [20] -> [30] -> [40] -> (back to 10)
*/
void insertatfront(int data){   
 
    node *temp = createnode(data);

    if(head==NULL){
        head = tail = temp;
        tail->next = head;
        printf("%d -> Inserted!\n", data);
        return;
    }
    temp->next = head;
    head = temp;
    tail->next = head;
    if (temp!=NULL){
            printf("%d -> Inserted!\n", data);
        }
        else{
            printf("Insertion failed!\n");
        }
    
}

void insertatend (int data){//sir aita koraise
    node *temp = createnode(data);
   
        if(head==NULL){
            head = tail = temp;
            tail->next = head;
            printf("%d -> Inserted!\n", data);
            return;
        }

        tail->next = temp;
        tail = temp;
        tail->next = head;
        if (temp!=NULL){
            printf("%d -> Inserted!\n", data);
        }
        else{
            printf("Insertion failed!\n");
        }
}
void delete (int value){/*cases:
1.List empty
2.Single node list
3.Value at head
4.Value at tail
5.Value in middle
6.Value not found*/
    int flag = 0;
    if(head==NULL){
       printf("Empty List!\n");
       return;
    }
    node *cur = head;
    node *prev = tail;
    //case: single node
    if(head==tail && head->data==value){
        free(head);
        head = tail = NULL;
        flag = 1;
        printf("%d -> Deleted!\n",value);
        return;
    }
    do{
        if(cur ->data ==value){
            //deleting head
            if(cur==head){
                head = head->next;
                tail->next = head;
            }
            //deteting tail
            else if(cur==tail){
                tail = prev;
                tail->next = head;
            }
            //deleting mid
            else{
                prev->next = cur->next;
            }
            free(cur);
            flag = 1;
            break;
        }
        prev = cur;
        cur = cur->next;
    } while (cur != head);
    if(flag==1){
            printf("%d -> Deleted!\n",value);
    }
    else{
        printf("%d  Not Found!\n",value);
    }
}

void search(int value){
  if(head==NULL){
      printf("Empty list!\n");
      return;
  }
  node *temp = head;
  int flag = 0;

  do {
    if(temp->data!=value){
        temp=temp->next;
    }
    else{
        flag = 1;
        break;
    }
  } while (temp != head);
  if(flag){
    printf("%d -> Found!\n",value);  
}
   else{
     printf("%d -> Not Found!\n",value);
   }
}

void print(){
    if(head==NULL){
        printf("Nothing to Print! \n");
    }
    else{
        printf("Linked List : ");
        node *temp = head;
        do{
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("Back to the head\n");
    }
}


int main(){
    print();
    delete(2023);
    search(1971);
    insertatend(5);
    insertatend(15);
    print();
    insertatend(56);
    search(15);
    insertatend(25);
    print();
    search(1952);
    delete(15);
    print();
    search(15);
    delete(404);
    print();
    insertatend(100);
    print();
    search(100);
    print();
    delete(5);
    print();
    delete(100);
    print();
    return 0;
}