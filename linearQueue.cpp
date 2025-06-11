#include<iostream>  // Include the Input/Output Stream Library for console operations
using namespace std;  // Use the standard namespace to avoid typing std::

const int capacity = 5;  // Define the fixed capacity/size of the queue

class linearQueue {
private:
    int queue[capacity];  // Array to store queue elements (fixed size)
    int front;           // Index pointer for the front of the queue
    int rear;            // Index pointer for the rear of the queue

public:
    // Constructor - initializes the queue
    linearQueue() {
        front = -1;  // Initialize front to -1 (indicates empty queue)
        rear = -1;   // Initialize rear to -1 (indicates empty queue)
    }

    // Check if queue is empty
    bool isEmpty() {
        // Queue is empty if both front and rear are -1
        return (front == -1 && rear == -1);
    }

    // Check if queue is full
    bool isFull() {
        // Queue is full if rear is at last index (capacity-1)
        return (rear == capacity-1);
    }

    // Add an element to the queue (enqueue operation)
    void enqueue(int value) {
        if(isFull()) {  // Check if queue is full first
            cout << "Queue is Full! Cannot enqueue " << value << endl;
            return;  // Exit if full
        }
        if(isEmpty()) {  // If queue was empty
            front = 0;   // Set front to 0 (first position)
        }
        rear++;  // Move rear pointer forward
        queue[rear] = value;  // Store the value at rear position
        cout << "Enqueued " << value << " in Queue" << endl;  // Print confirmation
    }

    // Remove an element from the queue (dequeue operation)
    void dequeue() {
        if(isEmpty()) {  // Check if queue is empty first
            cout << "Queue is empty. Cannot Dequeue" << endl;
            return;  // Exit if empty
        }
        int value = queue[front];  // Get the front element
        if(front == rear) {  // If this was the last element
            front = rear = -1;  // Reset queue to empty state
        }
        else {
            front++;  // Otherwise just move front pointer forward
        }
        cout << "Dequeued " << value << " From the queue" << endl;  // Print confirmation
    }

    // Display all elements in the queue
    void display() {
        if(isEmpty()) {  // Check if queue is empty
            cout << "Queue is empty" << endl;
            return;  // Exit if empty
        }
        cout << "Queue elements: ";
        // Loop through elements from front to rear
        for(int i = front; i <= rear; i++) {
            cout << queue[i] << " ";  // Print each element
        }
        cout << endl;  // New line after display
    }
};

int main() {
    linearQueue q;  // Create a queue object

    // Test enqueue operations
    q.enqueue(1);  // Add 1 to queue
    q.enqueue(2);  // Add 2 to queue
    q.enqueue(3);  // Add 3 to queue
    q.enqueue(4);  // Add 4 to queue
    q.enqueue(5);  // Add 5 to queue (queue now full)
    q.enqueue(6);  // Try to add 6 (will show queue is full)

    q.display();  // Display current queue (should show 1 2 3 4 5)

    // Test dequeue operations
    q.dequeue();  // Remove 1 (front element)
    q.dequeue();  // Remove 2 (new front element)

    q.display();  // Display current queue (should show 3 4 5)

    q.enqueue(6);  // Add 6 to available space
    q.display();   // Display queue (should show 3 4 5 6)

    return 0;  // End program
}