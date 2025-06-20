#include <iostream>
#define MAX_SIZE 100

using namespace std;

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    // Constructor to initialize stack
    Stack() {
        top = -1;
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed to stack\n";
    }

    // Function to pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from empty stack\n";
            return -1;
        }
        return arr[top--];
    }

    // Function to get the top element of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    // Function to check if stack is empty
    bool isEmpty() {
        return (top == -1);
    }

    // Function to check if stack is full
    bool isFull() {
        return (top == MAX_SIZE - 1);
    }

    // Function to display all elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Function to get the size of the stack
    int size() {
        return top + 1;
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\nStack Operations:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Size\n";
        cout << "6. Check if empty\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                value = s.pop();
                if (value != -1) {
                    cout << "Popped value: " << value << endl;
                }
                break;
            case 3:
                value = s.peek();
                if (value != -1) {
                    cout << "Top element: " << value << endl;
                }
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "Stack size: " << s.size() << endl;
                break;
            case 6:
                cout << "Stack is " << (s.isEmpty() ? "empty" : "not empty") << endl;
                break;
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}