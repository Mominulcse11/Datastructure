#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node *head = NULL;
node *tail = NULL;

/* CREATE NODE */
node* createnode(int value) {
    node *temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        printf("Heap memory exhausted\n");
        return NULL;
    }
    temp->data = value;
    temp->next = NULL;
    return temp;
}

/* INSERT AT END */
void insertatend(int value) {
    node *temp = createnode(value);
    if (temp == NULL) {
        printf("Heap Overflow!\n");
        return;
    }
    if (head == NULL) {
        head = tail=temp;
        printf("%d -> Inserted\n", value);
        return;
    }
    tail->next = temp;
    tail = temp;
      printf("%d -> Inserted\n", value);
}

/* PRINT LIST */
void print() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    node *temp = head;
    printf("The list is: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void  deleteatbegin(){
    if(head == NULL){
        printf("List is empty!\n");
        return ;
    }
    node *temp = head;
    printf("%d ->Deleted at begin\n", temp->data);
    head = temp->next;
    free(temp);

}
void deleteatend(){
     if(head == NULL){
        printf("List is empty!\n");
        return ;
    }
    if (head->next == NULL) {
        printf("%d -> Deleted at end\n", head->data);
        free(head);
        head = tail = NULL;
        return;
    }
    node *temp = head;
    while(temp->next!=tail){   //not temp->next!=NULL
        temp = temp->next;
    }
    printf("%d ->Deleted at end\n", tail->data);
    
    free(tail);
    temp->next = NULL;
    tail = temp;
    
}

/* DELETE BY VALUE */

void deletebyvalue (int value){
    /*cases:
    1.List empty
    2.Single node list
    3.Value at head
    4.Value at tail
    5.Value in middle
    6.Value not found*/
    
    int flag = 0;
    
    // Case 1: List empty
    if(head==NULL){
       printf("Empty List!\n");
       return;
    }
    
    node *cur = head;
    node *prev = NULL; 

    // Case 2: Single node list
    if(head==tail && head->data==value){
        free(head);
        head = tail = NULL;
        flag = 1;
        printf("%d -> Deleted!\n",value);
        return;
    }
    while (cur != NULL) { 
        if(cur->data == value){
            
            // Case 3: Deleting head
            if(cur == head){
                head = head->next;//head update
            }
            
            // Case 4: Deleting tail
            else if(cur == tail){
                tail = prev;//tail updata
                tail->next = NULL; 
            } 
            // Case 5: Deleting mid
            else{
                prev->next = cur->next;//right left re milao
            }
            free(cur);
            flag = 1;
            break; 
        }
        prev = cur;
        cur = cur->next;
    }
    if(flag == 1){
        printf("%d -> Deleted!\n", value);
    }
    else{
        printf("%d Not Found!\n", value);
    }
}
/* DELETE AT Kth POSITION (1-based) */
void deleteatkth(int k) {
    if (head == NULL || k <= 0) {
        printf("Invalid operation\n");
        return;
    }

    node *temp = head;

    /* Delete first node */
    if (k == 1) {
        head = temp->next;
        free(temp);
        return;
    }

    for (int i = 1; i < k - 1; i++) {
        if (temp->next == NULL) {
            printf("Invalid position\n");
            return;
        }
        temp = temp->next;
    }

    node *todelete = temp->next;
    if (todelete == NULL) {
        printf("Invalid position\n");
        return;
    }

    temp->next = todelete->next;
    free(todelete);
}

/* DELETE NODE WITHOUT HEAD POINTER */
void deleteNodeWithoutHead(node *temp) {
    if (temp == NULL || temp->next == NULL) {
        printf("Cannot delete this node without head\n");
        return;
    }

    node *nextNode = temp->next;
    temp->data = nextNode->data;
    temp->next = nextNode->next;
    free(nextNode);
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

/* MAIN */
int main() {

    insertatend(3);
    insertatend(1);
    insertatend(7);
    insertatend(6);
    insertatend(2);
    insertatend(9);

    print();

    int k;
    printf("Enter kth position to delete: ");
    scanf("%d", &k);

    deleteatkth(k);
    print();

    deletebyvalue(9);
    deleteatbegin();
    deleteatend();
    print();

    /* Find node with value 7 */
    node *node7 = head;
    while (node7 != NULL && node7->data != 7) {
        node7 = node7->next;
    }

    deleteNodeWithoutHead(node7);
    print();
    node *todelete = deleteMiddle();
    printf("After deleting the middle the linked list is : \n");
    print();

    return 0;
}
