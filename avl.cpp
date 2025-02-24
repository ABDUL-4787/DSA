#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
        height = 1;  // Initial height is 1
    }
};

class AVL {
public:
    // Get height of a node
    int getHeight(Node* node) {
        return (node == nullptr) ? 0 : node->height;
    }

    // Get balance factor
    int getBalanceFactor(Node* node) {
        return (node == nullptr) ? 0 : getHeight(node->left) - getHeight(node->right);
    }

    // Right Rotation (LL Case)
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    // Left Rotation (RR Case)
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    // Insert into AVL Tree
    Node* insert(Node* root, int val) {
        if (root == nullptr) return new Node(val);

        if (val < root->data) {
            root->left = insert(root->left, val);
        } else if (val > root->data) {
            root->right = insert(root->right, val);
        } else {
            return root; // No duplicate values allowed
        }

        // Update height
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

        // Get balance factor
        int balance = getBalanceFactor(root);

        // **Rotations to balance the tree**
        // Left-Left (LL) Case
        if (balance > 1 && val < root->left->data)
            return rightRotate(root);

        // Right-Right (RR) Case
        if (balance < -1 && val > root->right->data)
            return leftRotate(root);

        // Left-Right (LR) Case
        if (balance > 1 && val > root->left->data) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right-Left (RL) Case
        if (balance < -1 && val < root->right->data) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    // Inorder Traversal (Sorted Order)
    void inorder(Node* root) {
        if (root == nullptr) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    // Search in AVL Tree
    bool search(Node* root, int key) {
        while (root != nullptr) {
            if (root->data == key) return true;
            root = (key < root->data) ? root->left : root->right;
        }
        return false;
    }
};

int main() {
    AVL tree;
    Node* root = nullptr;
    int n, value, key;

    // Take user input for insertion
    cout << "Enter number of elements to insert: ";
    cin >> n;

    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = tree.insert(root, value);
    }

    // Display sorted elements using inorder traversal
    cout << "Inorder Traversal (Sorted AVL Tree): ";
    tree.inorder(root);
    cout << endl;

    // Search for a value
    cout << "Enter a value to search: ";
    cin >> key;

    if (tree.search(root, key))
        cout << "Key " << key << " found in AVL Tree!" << endl;
    else
        cout << "Key " << key << " not found in AVL Tree." << endl;

    return 0;
}

