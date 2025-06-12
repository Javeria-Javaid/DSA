#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedListQueue {
private:
    Node* front;
    Node* rear;
    int size;
    const int MAX_SIZE = 100;  // Optional: To simulate isFull()

public:
    LinkedListQueue() : front(nullptr), rear(nullptr), size(0) {}

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Check if the queue is full (optional, since linked lists can grow dynamically)
    bool isFull() {
        return size == MAX_SIZE;  // Remove if dynamic growth is desired
    }

    // Add an element to the rear (enqueue)
    void Enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << element << endl;
            return;
        }

        Node* newNode = new Node(element);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
        cout << "Enqueued: " << element << endl;
    }

    // Remove an element from the front (dequeue)
    void Dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        cout << "Dequeued: " << temp->data << endl;
        delete temp;
        size--;

        if (front == nullptr) {
            rear = nullptr;  // Reset rear if queue becomes empty
        }
    }

    // Check if an element exists in the queue
    bool isInList(int element) {
        Node* current = front;
        while (current != nullptr) {
            if (current->data == element) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Display all elements in the queue
    void Display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* current = front;
        cout << "Queue: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~LinkedListQueue() {
        while (!isEmpty()) {
            Dequeue();
        }
    }
};

int main() {
    LinkedListQueue q;

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Display();  // Output: 10 20 30

    q.Dequeue();   // Output: Dequeued: 10
    q.Display();   // Output: 20 30

    cout << "Is 20 in the queue? " << (q.isInList(20) ? "Yes" : "No") << endl;  // Yes
    cout << "Is 40 in the queue? " << (q.isInList(40) ? "Yes" : "No") << endl;  // No

    q.Dequeue();   // Output: Dequeued: 20
    q.Dequeue();   // Output: Dequeued: 30
    q.Dequeue();   // Output: Queue is empty.

    return 0;
}