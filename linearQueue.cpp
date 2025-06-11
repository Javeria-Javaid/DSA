#include<iostream>  // Standard input/output stream library for cout/cin
using namespace std; // Avoids needing to prefix std:: before standard functions

const int capacity = 5; // Maximum number of elements the queue can hold

class linearQueue {
private:
    int queue[capacity]; // Fixed-size array to store queue elements
    int front;          // Tracks the index of the front element
    int rear;           // Tracks the index of the rear element

public:
    // Constructor - Initializes an empty queue
    linearQueue() {
        front = -1; // -1 indicates empty queue
        rear = -1;  // -1 indicates empty queue
    }

    // Check if queue is empty
    bool isEmpty() {
        // Both front and rear at -1 means empty
        return (front == -1 && rear == -1);
    }

    // Check if queue is full
    bool isFull() {
        // Rear at last index means full
        return (rear == capacity - 1);
    }

    // Add element to the rear of queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full! Cannot enqueue " << value << endl;
            return; // Exit if no space
        }
        if (isEmpty()) {
            front = 0; // Initialize front on first enqueue
        }
        rear++; // Move rear pointer forward
        queue[rear] = value; // Store value at new rear position
        cout << "Enqueued " << value << " in Queue" << endl;
    }

    // Remove element from front of queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot Dequeue" << endl;
            return; // Exit if empty
        }
        int value = queue[front]; // Get front element
        if (front == rear) {
            // Last element being removed - reset queue
            front = rear = -1;
        } else {
            front++; // Move front pointer forward
        }
        cout << "Dequeued " << value << " from the queue" << endl;
    }

    // View front element without removal
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to peek." << endl;
        } else {
            cout << "Front element is: " << queue[front] << endl;
        }
    }

    // Search for value in queue
    bool isInList(int value) {
        if (isEmpty()) {
            return false; // Empty queue contains nothing
        }
        // Linear search through queue elements
        for (int i = front; i <= rear; i++) {
            if (queue[i] == value) {
                return true; // Found match
            }
        }
        return false; // No match found
    }

    // Display all queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        // Print from front to rear
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    linearQueue q; // Create queue instance

    // Test enqueue operations
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5); // Queue now full
    q.enqueue(6); // Should show full warning

    q.display(); // Show current queue (1-5)

    // Test dequeue operations
    q.dequeue(); // Remove 1
    q.dequeue(); // Remove 2

    q.display(); // Show queue (3-5)

    q.enqueue(6); // Add to available space
    q.display();  // Show queue (3-6)

    // Test peek functionality
    q.peek(); // Should show 3

    // Test search functionality
    int valueToCheck = 4;
    if (q.isInList(valueToCheck)) {
        cout << valueToCheck << " is in the queue." << endl;
    } else {
        cout << valueToCheck << " is NOT in the queue." << endl;
    }
    return 0; // Indicate successful completion
}