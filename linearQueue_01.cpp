#include<iostream>
using namespace std;

const int capacity = 5;

class linearQueue {
private:
  int queue[capacity];
  int front;
  int rear;

public:
  linearQueue() {
    front = -1;
    rear = -1;
  }

  bool isEmpty() {
    return (front == -1 && rear == -1);
  }

  bool isFull() {
    return (rear == capacity-1);
  }

  void enqueue(int value) {
    if(isFull()) {
      cout << "Queue is Full! Cannot enqueue " << value << endl;
      return;
    }
    if(isEmpty()) {
      front = 0;  // Initialize front when adding first element
    }
    rear++;
    queue[rear] = value;
    cout << "Enqueued " << value << " in Queue" << endl;
  }

  void dequeue() {
    if(isEmpty()) {
      cout << "Queue is empty. Cannot Dequeue" << endl;
      return;
    }
    int value = queue[front];
    if(front == rear) {
      front = rear = -1;  // Reset when last element is removed
    }
    else {
      front++;
    }
    cout << "Dequeued " << value << " From the queue" << endl;
  }

  void display() {
    if(isEmpty()) {
      cout << "Queue is empty" << endl;
      return;
    }
    cout << "Queue elements: ";
    for(int i = front; i <= rear; i++) {
      cout << queue[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  linearQueue q;

  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);
  q.enqueue(6);  // Should show queue is full

  q.display();

  q.dequeue();
  q.dequeue();

  q.display();

  q.enqueue(6);
  q.display();

  return 0;
}