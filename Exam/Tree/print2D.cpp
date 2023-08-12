#include<bits/stdc++.h>
using namespace std;

typedef struct node Node;
struct node {
    int data;
    Node *left = NULL, *right = NULL;
};

Node* getNode(int item) {
    Node *p = (Node*) malloc(sizeof(Node));
    p->data = item;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void print_2D(Node* root, int space) {
    if(root == NULL) return;
    space += 1;
    print_2D(root->right, space);
    for(int i = 1; i < space; i++) cout<<"\t";
    cout << root->data << endl;
    print_2D(root->left, space);
}

Node* Insert(Node* root, int item) {
    if(root == NULL) {
        root = getNode(item);
        return root;
    }
    if(root->data == item) {
        return root;
    }
    if(item <= root->data) {
        root->left = Insert(root->left, item);
    }
    else {
        root->right = Insert(root->right, item);
    }
}

void create(Node* &root) {
    cout << "Enter the number of nodes : ";
    int number;
    cin >> number;

    for(int i = 0; i < number; i++) {
        cout << "Enter the data : ";
        int d;
        cin >> d;
        if(root == NULL) root = Insert(root, d);
        else Insert(root, d);
    }
}

int main() {
    Node* root = NULL;

    create(root);

    print_2D(root, 0);

    return 0;
}
