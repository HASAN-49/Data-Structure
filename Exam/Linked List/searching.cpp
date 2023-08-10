#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;

Node* getNode() {
    Node* p;
    p = (Node*) malloc(sizeof(struct node));
    return p;
}

void display(Node* head) {
    Node* tmp = head;
    while(tmp != NULL) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void create(Node* &head, int a[], int n) {
    Node* ptr = head;
    for(int i = 0; i < n; i++) {
        //cout << a[i] << endl;
        Node* tmp;
        tmp = getNode();
        if(tmp == NULL) {
            cout << "NULL\n";
            return;
        }
        tmp->data = a[i];
        tmp->next = NULL;
        if(head == NULL) {
            head = tmp;
            ptr = tmp;
        }
        else {
            ptr->next = tmp;
            ptr = ptr->next;
        }
    }
}

void searching(Node* head, int item) {
    Node* tmp = head;
    int cnt = 0;
    while(tmp != NULL) {
        cnt++;
        if(tmp->data == item) {
            cout << item << " was found at postion " << cnt << endl;
            return;
        }
        tmp = tmp->next;
    }
    cout << item << " was not found in the list...\n";
}

int main() {
    int a[] = {5, 3, 9, 42, 0, 10};
    int n = sizeof(a) / sizeof(a[0]);

    Node* head;
    head = NULL;
    create(head, a, n);
    cout << "The list we have : ";
    display(head);

    cout << "Enter a value to search : ";
    int val;
    cin >> val;
    searching(head, val);

    return 0;
}


