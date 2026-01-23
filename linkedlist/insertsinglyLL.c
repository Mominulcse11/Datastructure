#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node *head = NULL;

/* CREATE NODE */
node* createnode(int value) {
    node *temp = malloc(sizeof(node));
    if (temp == NULL) {
        printf("Heap memory exhausted\n");
        return NULL;
    }
    temp->data = value;
    temp->next = NULL;
    return temp;
}

/* INSERT AT BEGIN */
void insertatbegin(int value) {
    node *temp = createnode(value);
    if (temp == NULL) return;

    temp->next = head;
    head = temp;
}

/* INSERT AT END */
void insertatend(int value) {
    node *t = createnode(value);
    if (t == NULL) return;

    if (head == NULL) {
        head = t;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = t;
}

/* INSERT AT Kth POSITION (1-based) */
void insertatkth(int value, int pos) {
    if (pos <= 0) {
        printf("Invalid position\n");
        return;
    }

    node *t = createnode(value);
    if (t == NULL) return;

    /* Insert at beginning */
    if (pos == 1) {
        t->next = head;
        head = t;
        return;
    }

    if (head == NULL) {
        printf("Position out of range\n");
        free(t);
        return;
    }

    node *temp = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp->next == NULL) {
            printf("Position out of range\n");
            free(t);
            return;
        }
        temp = temp->next;
    }

    t->next = temp->next;
    temp->next = t;
}

/* PRINT LIST */
void print() {
    if (head == NULL) {
        printf("List is empty\n");
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

int main() {

    insertatbegin(3);
    insertatbegin(1);
    insertatbegin(7);

    insertatend(5);
    insertatkth(90, 5);

    print();
    return 0;
}

/* jodi head locally run kori


void insertatbegin(node** head,int value){
  node *temp=createnode(value);
    if (*head != NULL)
    {
        temp->next = *head;
    }
      *head = temp;
}
      insertatbegin(&head,3);
      */