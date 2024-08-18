#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int queue[MAX_SIZE];
int front = -1, rear = -1;

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return rear == MAX_SIZE - 1;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full. " << endl;
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        cout << "Enqueued " << value << " into the queue." << endl;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. " << endl;
    } else {
        int dequeuedValue = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        cout << "Dequeued " << dequeuedValue << " from the queue." << endl;
    }
}

void deleteNegatives() {
    int nonNegativeIndex = front;
    for (int i = front; i <= rear; i++) {
        if (queue[i] >= 0) {
            queue[nonNegativeIndex] = queue[i];
            nonNegativeIndex++;
        }
    }
    rear = nonNegativeIndex - 1;
    if (rear == front - 1) {
        front = rear = -1;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}


void queueFromStack(int stack[], int stackSize) {
    if (isEmpty()) {
        for (int i = 0; i < stackSize; i++) {
            enqueue(stack[i]);
        }
        cout << "Queue created from the stack." << endl;
    } else {
        cout << "Queue is not empty." << endl;
    }
}

void copyQueue(int destination[], int& destFront, int& destRear) {
    destFront = front;
    destRear = rear;

    for (int i = front; i <= rear; i++) {
        destination[i] = queue[i];
    }
}

int main() {
    int choice, value;

    while (choice != 6) {
        cout << "\nQueue Operations:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Delete All Negative Numbers" << endl;
        cout << "4. Display" << endl;
        cout << "5. Copy Queue" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value to enqueue: ";
            cin >> value;
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            deleteNegatives();
            cout << "Negative numbers deleted from the queue." << endl;
            break;
        case 4:
            display();
            break;

        case 5: {
            int copiedQueue[MAX_SIZE];
            int copiedFront, copiedRear;
            copyQueue(copiedQueue, copiedFront, copiedRear);
            cout << "Copied Queue elements: ";
            for (int i = copiedFront; i <= copiedRear; i++) {
                cout << copiedQueue[i] << " ";
            }
            cout << endl;
            break;
        }
        case 6:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
