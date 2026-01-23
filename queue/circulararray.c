#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear  = -1;

/* ENQUEUE */
void enqueue(int value) {
    // Overflow check
    if ((rear + 1) % SIZE == front) {
        printf("Queue overflow\n");
        return;
    }

    // First insertion
    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = value;
}

/* DEQUEUE */
int dequeue() {
    if (front == -1) {
        printf("Queue underflow\n");
        return -1;
    }

    int value = queue[front];

    // Last element removal
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }

    return value;
}

/* PEEK */
int peek() {
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue[front];
}

/* DISPLAY */
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    printf("Dequeued: %d\n", dequeue());
    printf("Front element: %d\n", peek());

    enqueue(50);
    enqueue(60);   // tests circular wrap-around

    display();

    return 0;
}
