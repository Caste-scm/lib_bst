#include <iostream>
using namespace std;
class Node {
private:
    int data;
    Node* lchild;
    Node* rchild;
public:
    Node(int d) : data(d), lchild(nullptr), rchild(nullptr) {};
    Node* insertR(int k);
    void inOrder();
};
Node* Node::insertR(int k) {
    Node* current = this;
    Node* parent = nullptr;
    while (current != nullptr) {
        parent = current;
        if (k < current->data) {
            current = current->lchild;
        } else {
            current = current->rchild;
        }
    }
    if (k < parent->data) {
        parent->lchild = new Node(k);
    } else {
        parent->rchild = new Node(k);
    }
    return this;
}
void Node::inOrder() {
    if (lchild != nullptr) lchild->inOrder();
    cout << data << " ";
    if (rchild != nullptr) rchild->inOrder();
}