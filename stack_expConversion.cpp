#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to get precedence of an operator
int precedence(char op) {
    if(op == '^') return 4;
    if(op == '*' || op == '/') return 3;
    if(op == '+' || op == '-') return 2;
    return 0;
}

// Function to check if character is opening parenthesis
bool isOpeningParenthesis(char c) {
    return c == '(' || c == '{' || c == '[';
}

// Function to check if character is closing parenthesis
bool isClosingParenthesis(char c) {
    return c == ')' || c == '}' || c == ']';
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix;
    
    for(char c : infix) {
        if(isalnum(c)) {
            postfix += c;
        }
        else if(isOpeningParenthesis(c)) {
            s.push(c);
        }
        else if(isClosingParenthesis(c)) {
            while(!s.empty() && !isOpeningParenthesis(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Remove the opening parenthesis
        }
        else if(isOperator(c)) {
            while(!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    
    while(!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    
    return postfix;
}

// Function to convert infix to prefix
string infixToPrefix(string infix) {
    // Reverse the infix expression
    reverse(infix.begin(), infix.end());
    
    // Replace ( with ) and vice versa
    for(int i = 0; i < infix.size(); i++) {
        if(infix[i] == '(') infix[i] = ')';
        else if(infix[i] == ')') infix[i] = '(';
    }
    
    // Get postfix of reversed infix
    string prefix = infixToPostfix(infix);
    
    // Reverse the postfix to get prefix
    reverse(prefix.begin(), prefix.end());
    
    return prefix;
}

// Function to evaluate postfix expression
int evaluatePostfix(string postfix) {
    stack<int> s;
    
    for(char c : postfix) {
        if(isdigit(c)) {
            s.push(c - '0');
        }
        else {
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();
            
            switch(c) {
                case '+': s.push(operand1 + operand2); break;
                case '-': s.push(operand1 - operand2); break;
                case '*': s.push(operand1 * operand2); break;
                case '/': s.push(operand1 / operand2); break;
                case '^': s.push(pow(operand1, operand2)); break;
            }
        }
    }
    
    return s.top();
}

int main() {
    string infix, postfix, prefix;
    int choice;
    
    do {
        cout << "\nExpression Conversion Menu:\n";
        cout << "1. Infix to Postfix\n";
        cout << "2. Infix to Prefix\n";
        cout << "3. Evaluate Postfix\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer
        
        switch(choice) {
            case 1:
                cout << "Enter infix expression: ";
                getline(cin, infix);
                postfix = infixToPostfix(infix);
                cout << "Postfix expression: " << postfix << endl;
                break;
            case 2:
                cout << "Enter infix expression: ";
                getline(cin, infix);
                prefix = infixToPrefix(infix);
                cout << "Prefix expression: " << prefix << endl;
                break;
            case 3:
                cout << "Enter postfix expression: ";
                getline(cin, postfix);
                cout << "Result: " << evaluatePostfix(postfix) << endl;
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while(choice != 4);
    
    return 0;
}