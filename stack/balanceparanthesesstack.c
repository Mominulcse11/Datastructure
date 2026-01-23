#include <stdio.h>
#include <stdlib.h>

// Stack node
struct node {
    char data;
    struct node *next;
};

// Global stack head
struct node *head = NULL;

// Push to stack
void push(char ch) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = ch;
    temp->next = head;
    head = temp;
}

// Pop from stack
char pop() {
    if (head == NULL)
        return '\0';

    struct node *temp = head;
    char popped = temp->data;
    head = head->next;
    free(temp);
    return popped;
}

// Check matching pair
int isMatching(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

// Check balanced parentheses
int isBalanced(char expr[]) {
    int i = 0;
    char popped;

    while (expr[i] != '\0') {

        // Opening bracket → push
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(expr[i]);
        }

        // Closing bracket → pop & match
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            if (head == NULL)
                return 0;  // no opening bracket

            popped = pop();
            if (!isMatching(popped, expr[i]))
                return 0;  // mismatch
        }
        i++;
    }

    // If stack empty → balanced
    return (head == NULL);
}

int main() {
    char expr[100];

    printf("Enter expression: ");
    scanf("%s", expr);

    if (isBalanced(expr))
        printf("Balanced parentheses\n");
    else
        printf("Not balanced parentheses\n");

    return 0;
}
