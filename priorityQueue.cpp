#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;         // The actual value
    int priority;     // Priority (higher number = higher priority)
    Node* next;       // Pointer to next node
};

Node* front = NULL;   // Front of the queue

// Insert with priority
void enqueue(int value, int prio) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->priority = prio;
    newNode->next = NULL;

    // If queue is empty or new node has highest priority
    if (front == NULL || prio > front->priority) {
        newNode->next = front;
        front = newNode;
    }
    else {
        // Find the correct position based on priority
        Node* temp = front;
        while (temp->next != NULL && temp->next->priority >= prio) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Remove highest priority element
int dequeue() {
    if (front == NULL) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    Node* temp = front;
    int removedValue = temp->data;
    front = front->next;
    delete temp;  // Free memory
    return removedValue;
}

// Display the queue
void display() {
    if (front == NULL) {
        cout << "Queue is empty!" << endl;
        return;
    }
    Node* temp = front;
    cout << "Queue: ";
    while (temp != NULL) {
        cout << temp->data << "(" << temp->priority << ") ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    enqueue(10, 1);  // (value, priority)
    enqueue(20, 3);
    enqueue(30, 2);
    enqueue(40, 5);

    display();  // Output: 40(5) 20(3) 30(2) 10(1)

    cout << "Dequeued: " << dequeue() << endl; // 40 (highest priority)
    cout << "Dequeued: " << dequeue() << endl; // 20

    display();  // Output: 30(2) 10(1)

    return 0;
}