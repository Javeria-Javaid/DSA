#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

int height(Node* node) {
    return node ? node->height : 0;
}

int getBalance(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

Node* newNode(int key) {
    Node* node = new Node;
    node->data = key;
    node->left = node->right = nullptr;
    node->height = 1;
    return node;
}

Node* rotateRight(Node* b) {
    Node* a = b->left;
    Node* temp = a->right;

    a->right = b;
    b->left = temp;

    b->height = 1 + max(height(b->left), height(b->right));
    a->height = 1 + max(height(a->left), height(a->right));

    return a;
}

Node* rotateLeft(Node* a) {
    Node* b = a->right;
    Node* temp = b->left;

    b->left = a;
    a->right = temp;

    a->height = 1 + max(height(a->left), height(a->right));
    b->height = 1 + max(height(b->left), height(b->right));

    return b;
}

Node* insert(Node* node, int n) {
    if (!node) return newNode(n);

    if (n < node->data)
        node->left = insert(node->left, n);
    else if (n > node->data)
        node->right = insert(node->right, n);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    // Balancing
    if (balance > 1 && n < node->left->data) // LL
        return rotateRight(node);
    if (balance < -1 && n > node->right->data) // RR
        return rotateLeft(node);
    if (balance > 1 && n > node->left->data) { // LR
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && n < node->right->data) { // RL
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Get the node with the minimum value (used in delete)
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left)
        current = current->left;
    return current;
}

// Delete a node
Node* deleteNode(Node* root, int n) {
    if (!root) return root;

    // Standard BST delete
    if (n < root->data)
        root->left = deleteNode(root->left, n);
    else if (n > root->data)
        root->right = deleteNode(root->right, n);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (!root) return root;

    // Update height
    root->height = 1 + max(height(root->left), height(root->right));

    // Check balance
    int balance = getBalance(root);

    // Balance cases
    if (balance > 1 && getBalance(root->left) >= 0)
        return rotateRight(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return rotateLeft(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    int n, val;

    cout << "Enter number of elements to insert: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> val;
        root = insert(root, val);
    }

    cout << "\nIn-order traversal: ";
    inOrder(root);
    cout << "\n";

    cout << "Enter value to delete: ";
    cin >> val;

    root = deleteNode(root, val);

    cout << "In-order after deletion: ";
    inOrder(root);
    cout << "\n";

    return 0;
}