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

void preorder(Node* root) {
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;

    create(root);

    cout << "Preorder : ";
    preorder(root);
    cout << endl;

    cout << "Inorder : ";
    inorder(root);
    cout << endl;

    cout << "Postorder : ";
    postorder(root);
    cout << endl;

    return 0;
}
