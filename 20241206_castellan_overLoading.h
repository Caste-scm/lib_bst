#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {};
    friend ostream& operator<<(ostream& out, const Node& node) {
        out << node.data;
        return out;
    }
    friend istream& operator>>(istream& in, Node& node) {
        in >> node.data;
        return in;
    }
    Node* root;
    bool searchR(Node* node, int k) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == k) {
            return true;
        }
        if (k < node->data) {
            return searchR(node->left, k);
        } else {
            return searchR(node->right, k);
        }
    }
    Node* insertR(Node* node, int k) {
        if (node == nullptr) {
            return new Node(k);
        }
        if (k < node->data) {
            node->left = insertR(node->left, k);
        } else if (k > node->data) {
            node->right = insertR(node->right, k);
        }
        return node;
    }
    Node() : root(nullptr) {};
    bool searchI(int k) {
        Node* current = root;
        while (current != nullptr) {
            if (current->data == k) {
                return true;
            } else if (k < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    }
    bool searchR(int k) {
        return searchR(root, k);
    }
    void insertI(int k) {
        Node* newNode = new Node(k);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        Node* current = root;
        Node* parent = nullptr;
        while (current != nullptr) {
            parent = current;
            if (k < current->data) {
                current = current->left;
            } else if (k > current->data) {
                current = current->right;
            } else {
                return;
            }
        }
        if (k < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }
    void insertR(int k) {
        root = insertR(root, k);
    }
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }
    void printInorder() {
        inorder(root);
        cout << endl;
    }
};