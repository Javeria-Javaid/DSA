#include <iostream>
using namespace std;

// TreeNode structure
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a node in BST
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    
    return root;
}

// Inorder DFS traversal (Left-Root-Right)
void inorderDFS(TreeNode* root) {
    if (root == nullptr) return;
    
    inorderDFS(root->left);
    cout << root->data << " ";
    inorderDFS(root->right);
}

// Preorder DFS traversal (Root-Left-Right)
void preorderDFS(TreeNode* root) {
    if (root == nullptr) return;
    
    cout << root->data << " ";
    preorderDFS(root->left);
    preorderDFS(root->right);
}

// Postorder DFS traversal (Left-Right-Root)
void postorderDFS(TreeNode* root) {
    if (root == nullptr) return;
    
    postorderDFS(root->left);
    postorderDFS(root->right);
    cout << root->data << " ";
}

int main() {
    TreeNode* root = nullptr;
    
    // Insert elements into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    cout << "Inorder DFS traversal: ";
    inorderDFS(root);
    cout << endl;
    
    cout << "Preorder DFS traversal: ";
    preorderDFS(root);
    cout << endl;
    
    cout << "Postorder DFS traversal: ";
    postorderDFS(root);
    cout << endl;
    
    return 0;
}