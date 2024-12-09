#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
    friend ostream& operator<<(ostream& out, const Node& node) {
        out << "Node value: " << node.data;
        if (node.left != nullptr) {
            out << "Left child: " << node.left->data << endl;
        } else {
            out << "Left child: null" << endl;
        }
        if (node.right != nullptr) {
            out << "Right child: " << node.right->data << endl;
        } else {
            out << "Right child: null" << endl;
        }
        return out;
    }
    friend istream& operator>>(istream& in, Node& node) {
        cout << "Inserisci valore del nodo: ";
        in >> node.data;
        int leftValue;
        cout << "Inserisci valore del figlio sinistro: ";   //-1 = nullo
        in >> leftValue;
        if (leftValue != -1) {
            node.left = new Node(leftValue);
        } else {
            node.left = nullptr;
        }
        int rightValue;
        cout << "Inserisci valore del figlio destro: ";  //-1 = nullo
        in >> rightValue;
        if (rightValue != -1) {
            node.right = new Node(rightValue);
        } else {
            node.right = nullptr;
        }
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
    Node() : root(nullptr) {}
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
    void preOrder(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
    void preOrder() {
        preOrder(root);
        cout << endl;
    }
    void postOrder(Node* node) {
        if (node != nullptr) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->data << " ";
        }
    }
    void postOrder() {
        postOrder(root);
        cout << endl;
    }
    Node* deleteNode(Node* node, int k) {
        if (node == nullptr) {
            return node;
        }
        if (k < node->data) {
            node->left = deleteNode(node->left, k);
        } else if (k > node->data) {
            node->right = deleteNode(node->right, k);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
    void deleteNode(int k) {
        root = deleteNode(root, k);
    }
    bool isBST(Node* node, int minVal, int maxVal) {
        if (node == nullptr) {
            return true;
        }
        if (node->data <= minVal || node->data >= maxVal) {
            return false;
        }
        return isBST(node->left, minVal, node->data) && isBST(node->right, node->data, maxVal);
    }
    bool isBst() {
        return isBST(root, INT_MIN, INT_MAX);
    }
};
