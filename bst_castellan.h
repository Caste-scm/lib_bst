#include <iostream>
using namespace std;
struct Node{
    int value;
    int weight;
    Node* rchild;
    Node* lchild;
    Node(int v){
        value = v;
        weight = 1;
        rchild = nullptr;
        lchild = nullptr;
    }
};
Node* insert(Node* r,int k){
    if(r == nullptr){
        return new Node(k);
    }
    if(r->value == k){
        r->weight++;
        return r;
    }
    if(r->value > k){
        r->lchild = insert(r->lchild,k);
    }else{
        r->rchild = insert(r->rchild,k);
    }
    return r;
}
int MAX(int lc,int rc){
    if(lc>rc){
        return lc;
    }else{
        return rc;
    }
}
int altezza(Node* r){
    if(r==NULL){
        return 0;
    }
    int lc=altezza(r->lchild);
    int rc=altezza(r->rchild);
    return MAX(lc,rc)+1;
}
Node* insert_it(Node* r,int k){
    if(r == nullptr){
        return new Node(k);
    }
    Node* current = r;
    Node* father = nullptr;
    while(current != nullptr){
        father = current;
        if(current->value > k){
            current = current->lchild;
        }else if(current->value < k){
            current = current->rchild;
        }else if(current->value == k){
            current->weight++;
            return r;
        }
    }
    if(father->value > k){
        father->lchild = new Node(k);
    }else{
        father->rchild = new Node(k);
    }
    return r;
}
Node* deleteNode(Node* r, int k) {
    if (r == nullptr){
        return r;
    }    
    if (k < r->value) {
        r->lchild = deleteNode(r->lchild, k);
    }
    else if (k > r->value) {
        r->rchild = deleteNode(r->rchild, k);
    }
    else {
        if (r->lchild == nullptr && r->rchild == nullptr) {
            delete r;
            return nullptr;
        }
    }
    return r;
}
bool isBST(Node* r,Node* min =nullptr,Node* max =nullptr){
    if(r==nullptr){
        return true;
    }
    if(min != nullptr && r->value <= min->value){
        return false;
    }
    if(max != nullptr && r->value <= max->value){
        return false;
    }
    return isBST(r->lchild,min,r) && isBST(r->rchild,r,max);
}
Node* search_it(Node* r,int k){
    while(r != nullptr && r->value != k){
        if(r->value > k){
            r = r->lchild;
        }else if(r->value < k){
            r = r->rchild;
        }else if(r->value == k){
            return r;
        }
    }
    return r;
}
Node* search(Node* r,int k){
    if(r == nullptr){
        cout << "il valore non e' presente" << endl;
        return nullptr;
    }
    if(r->value == k){
        cout << "il valore e' presente" << endl;
        return nullptr;
    }
    if(r->value > k){
        search(r->lchild,k);
    }else{
        search(r->rchild,k);
    }
    return nullptr;
}
void preOrderTraversal(Node* r){
    if(r==NULL){
        return;
    }
    cout << r->value << ".";
    preOrderTraversal(r->lchild);
    preOrderTraversal(r->rchild);
}
void inOrderTraversal(Node* r){
    if(r==NULL){
        return;
    }
    inOrderTraversal(r->lchild);
    cout << r->value << ".";
    inOrderTraversal(r->rchild);
}
void postOrderTraversal(Node* r){
    if(r==NULL){
        return;
    }
    postOrderTraversal(r->lchild);
    postOrderTraversal(r->rchild);
    cout << r->value << ".";
}