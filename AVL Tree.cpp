#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    Node* root;

    // Utility function to get height of a node
    int height(Node *node) {
        return node ? node->height : 0;
    }

    // Update height of a node
    void updateHeight(Node *node) {
        node->height = 1 + max(height(node->left), height(node->right));
    }

    // Get balance factor
    int getBalance(Node *node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    // Right rotation
    Node* rightRotate(Node *y) {
        Node *x = y->left;
        Node *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        updateHeight(y);
        updateHeight(x);

        return x;
    }

    // Left rotation
    Node* leftRotate(Node *x) {
        Node *y = x->right;
        Node *T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        updateHeight(x);
        updateHeight(y);

        return y;
    }

    // Insert a node
    Node* insert(Node* node, int key) {
        // 1. Perform standard BST insertion
        if (!node) return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else // Duplicate keys not allowed
            return node;

        // 2. Update height of ancestor node
        updateHeight(node);

        // 3. Get balance factor
        int balance = getBalance(node);

        // 4. Rebalance if needed

        // Left Left Case
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Find node with minimum key value
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left)
            current = current->left;
        return current;
    }

    // Delete a node
    Node* deleteNode(Node* root, int key) {
        // 1. Perform standard BST delete
        if (!root) return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            // Node with one child or no child
            if (!root->left || !root->right) {
                Node* temp = root->left ? root->left : root->right;

                // No child case
                if (!temp) {
                    temp = root;
                    root = nullptr;
                } else // One child case
                    *root = *temp; // Copy contents

                delete temp;
            } else {
                // Node with two children
                Node* temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        // If tree had only one node
        if (!root) return root;

        // 2. Update height
        updateHeight(root);

        // 3. Get balance factor
        int balance = getBalance(root);

        // 4. Rebalance if needed

        // Left Left Case
        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        // Left Right Case
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        // Right Left Case
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    // Search for a key
    bool search(Node* root, int key) {
        if (!root) return false;
        if (key == root->key) return true;
        if (key < root->key) return search(root->left, key);
        return search(root->right, key);
    }

    // Traversal functions
    void inorder(Node* root) {
        if (root) {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }

    void preorder(Node* root) {
        if (root) {
            cout << root->key << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(Node* root) {
        if (root) {
            postorder(root->left);
            postorder(root->right);
            cout << root->key << " ";
        }
    }

public:
    AVLTree() : root(nullptr) {}

    // Public interface
    void insert(int key) {
        root = insert(root, key);
    }

    void remove(int key) {
        root = deleteNode(root, key);
    }

    bool search(int key) {
        return search(root, key);
    }

    void printInorder() {
        inorder(root);
        cout << endl;
    }

    void printPreorder() {
        preorder(root);
        cout << endl;
    }

    void printPostorder() {
        postorder(root);
        cout << endl;
    }

    int getHeight() {
        return height(root);
    }
};

int main() {
    AVLTree tree;

    // Insertion
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "Inorder traversal: ";
    tree.printInorder(); // 10 20 25 30 40 50

    cout << "Preorder traversal: ";
    tree.printPreorder(); // 30 20 10 25 40 50

    cout << "Postorder traversal: ";
    tree.printPostorder(); // 10 25 20 50 40 30

    // Search
    cout << "Search 25: " << (tree.search(25) ? "Found" : "Not found") << endl;
    cout << "Search 35: " << (tree.search(35) ? "Found" : "Not found") << endl;

    // Deletion
    tree.remove(30);
    cout << "After deleting 30, inorder: ";
    tree.printInorder(); // 10 20 25 40 50

    cout << "Tree height: " << tree.getHeight() << endl;

    return 0;
}