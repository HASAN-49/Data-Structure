#include<bits/stdc++.h>
using namespace std;

typedef struct node Node;
struct node {
    int data;
    Node *left = NULL, *right = NULL;
};

Node* getNode(int item) {
    Node* p = (Node*)malloc(sizeof(struct node));
    p->data = item;
    p->left = NULL;
    p->right = NULL;
    return p;
}

Node* Insert(Node *ptr, int item, string &s) {
    if(ptr == NULL) {
        ptr = getNode(item);
        return ptr;
    }
    if(ptr->data == item) {
        cout << "The value(" << item << ") was preserved at : ";
        cout << "root";
        int i = 0;
        while(s[i] != '\0') {
            cout << " -> ";
            if(s[i] == '0') cout << "left";
            else cout << "right";
            i++;
        }
        cout << endl;
        return ptr;
    }
    if(ptr->data > item) {
        s += '0';
        ptr->left = Insert(ptr->left, item, s);
    }
    else {
        s += '1';
        ptr->right = Insert(ptr->right, item, s);
    }
}

void create(Node* &root, int a[], int n) {
    cout << "Enter the values : \n";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        string pos = "";
        if(root == NULL) root = Insert(root, a[i], pos);
        else Insert(root, a[i], pos);
    }
}

void inorder(Node *root) {
    if(root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node *root = NULL;
    /*int a[] = {7, 6, 4, 5, 9, 8, 10, 25, 12, 9, 11, 2, 3, 1, 11};
    int n = sizeof(a) / sizeof(a[0]);*/

    cout << "Enter the size of the tree : ";
    int n;
    cin >> n;
    int a[n];

    create(root, a, n);
    inorder(root);
    cout << endl;

    return 0;
}
