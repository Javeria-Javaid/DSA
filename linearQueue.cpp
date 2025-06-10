#include <iostream>
using namespace std;

class LinearQueue {
private:
    int* queue;     // Dynamic array to store elements
    int front;      // Front index
    int rear;       // Rear index
    int capacity;   // Maximum capacity of the queue

public:
    // Constructor to initialize the queue
    LinearQueue(int size) {
        capacity = size;
        queue = new int[capacity];
        front = rear = -1;  // Empty queue
    }

    // Destructor to free memory
    ~LinearQueue() {
        delete[] queue;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check if the queue is full
    bool isFull() {
        return (rear == capacity - 1);
    }

    // Add an element to the rear of the queue (Enqueue)
    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is Full! Cannot enqueue." << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;  // First element
        }
        rear++;
        queue[rear] = item;
        cout << "Enqueued: " << item << endl;
    }

    // Remove an element from the front of the queue (Dequeue)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty! Cannot dequeue." << endl;
            return -1;  // Error code
        }
        int item = queue[front];
        if (front == rear) {  // Last element
            front = rear = -1;
        } else {
            front++;
        }
        cout << "Dequeued: " << item << endl;
        return item;
    }

    // Print the front element without removing it
    void printFront() {
        if (isEmpty()) {
            cout << "Queue is Empty! No front element." << endl;
        } else {
            cout << "Front element: " << queue[front] << endl;
        }
    }

    // Check if an element exists in the queue
    bool isInList(int element) {
        if (isEmpty()) {
            return false;
        }
        for (int i = front; i <= rear; i++) {
            if (queue[i] == element) {
                return true;
            }
        }
        return false;
    }

    // Display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    LinearQueue q(size);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();        // Output: 10 20 30
    q.printFront();     // Output: Front element: 10
    q.dequeue();        // Output: Dequeued: 10
    q.display();        // Output: 20 30

    cout << "Is 20 in the queue? " << (q.isInList(20) ? "Yes" : "No") << endl;  // Yes
    cout << "Is 50 in the queue? " << (q.isInList(50) ? "Yes" : "No") << endl;  // No

    return 0;
}