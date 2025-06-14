#include <iostream>
using namespace std;

const int MAX_SIZE = 5; // Maximum size of the queue

class CircularQueue {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    // Constructor to initialize front and rear
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    // Check if the queue is full
    bool isFull() {
        return ((rear + 1) % MAX_SIZE == front);
    }

    // Add an element to the queue (enqueue)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << endl;
            return;
        }
        else if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = value;
        cout << "Enqueued " << value << " to the queue" << endl;
    }

    // Remove an element from the queue (dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue" << endl;
            return;
        }
        else if (front == rear) {
            cout << "Dequeued " << arr[front] << " from the queue" << endl;
            front = rear = -1;
        }
        else {
            cout << "Dequeued " << arr[front] << " from the queue" << endl;
            front = (front + 1) % MAX_SIZE;
        }
    }

    // Get the front element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    // Check if a value exists in the queue
    bool isInList(int value) {
        if (isEmpty()) {
            return false;  // Empty queue contains nothing
        }

        int i = front;
        while (true) {
            if (arr[i] == value) {
                return true;  // Found match
            }
            if (i == rear) {
                break;  // Reached the end of the queue
            }
            i = (i + 1) % MAX_SIZE;  // Move to next index (wrap around if needed)
        }

        return false;  // No match found
    }

    // Display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX_SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display(); // Should display all 5 elements

    q.enqueue(60); // Should show queue is full

    // Check if elements exist in the queue
    cout << "Is 20 in the queue? " << (q.isInList(20) ? "Yes" : "No") << endl;
    cout << "Is 60 in the queue? " << (q.isInList(60) ? "Yes" : "No") << endl;

    q.dequeue();
    q.dequeue();

    q.display(); // Should display remaining elements

    q.enqueue(60); // Now we can enqueue again
    q.enqueue(70);

    q.display(); // Should show wrapped-around queue

    cout << "Front element is: " << q.peek() << endl;

    // Check if elements exist after modifications
    cout << "Is 10 in the queue? " << (q.isInList(10) ? "Yes" : "No") << endl;
    cout << "Is 70 in the queue? " << (q.isInList(70) ? "Yes" : "No") << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.dequeue(); // Should show queue is empty

    // Final check on empty queue
    cout << "Is 30 in the queue? " << (q.isInList(30) ? "Yes" : "No") << endl;

    return 0;
}