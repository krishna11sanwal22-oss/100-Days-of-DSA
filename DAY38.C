#include <stdio.h>
#define MAX 100

int arr[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

void push_front(int x) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }
    if (isEmpty())
        front = rear = 0;
    else if (front == 0)
        front = MAX - 1;
    else
        front--;

    arr[front] = x;
}

void push_back(int x) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }
    if (isEmpty())
        front = rear = 0;
    else if (rear == MAX - 1)
        rear = 0;
    else
        rear++;

    arr[rear] = x;
}

void pop_front() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }
    if (front == rear)
        front = rear = -1;
    else if (front == MAX - 1)
        front = 0;
    else
        front++;
}

void pop_back() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }
    if (front == rear)
        front = rear = -1;
    else if (rear == 0)
        rear = MAX - 1;
    else
        rear--;
}

int getFront() {
    if (isEmpty()) return -1;
    return arr[front];
}

int getRear() {
    if (isEmpty()) return -1;
    return arr[rear];
}

int size() {
    if (isEmpty()) return 0;
    if (rear >= front)
        return rear - front + 1;
    return MAX - front + rear + 1;
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", arr[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Push Front\n2. Push Back\n3. Pop Front\n4. Pop Back\n5. Front\n6. Rear\n7. Size\n8. Display\n9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push_front(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                push_back(value);
                break;

            case 3:
                pop_front();
                break;

            case 4:
                pop_back();
                break;

            case 5:
                printf("Front: %d\n", getFront());
                break;

            case 6:
                printf("Rear: %d\n", getRear());
                break;

            case 7:
                printf("Size: %d\n", size());
                break;

            case 8:
                display();
                break;

            case 9:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}