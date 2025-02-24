#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    // Insert function
    Node* insert(Node* root, int val) {
        if (root == nullptr) {
            return new Node(val);
        }
        if (val < root->data) {
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }
        return root;
    }

    // Inorder traversal
    void inorder(Node* root) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    // Search function
    bool search(Node* root, int key) {
        while (root != nullptr) {
            if (root->data == key) {
                return true;
            }
            root = (key < root->data) ? root->left : root->right;
        }
        return false;
    }
};

int main() {
    BST bst;
    Node* root = nullptr;

    int n, value, key;

    // Ask user how many values to insert
    cout << "Enter the number of elements to insert in BST: ";
    cin >> n;

    // Insert user-inputted values
    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = bst.insert(root, value);
    }

    // Display the BST using inorder traversal
    cout << "Inorder Traversal of BST: ";
    bst.inorder(root);
    cout << endl;

    // Ask user for a key to search
    cout << "Enter a key to search: ";
    cin >> key;

    if (bst.search(root, key)) {
        cout << "Key " << key << " found in the BST!" << endl;
    } else {
        cout << "Key " << key << " not found in the BST." << endl;
    }

    return 0;
}
