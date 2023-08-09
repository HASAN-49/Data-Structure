#include <bits/stdc++.h>
using namespace std;

typedef struct node Node;
struct node {
    int data;
    Node* next;
};

Node* getNode() {
    Node* p;
    p = (Node*) malloc(sizeof(struct node));
    return p;
}

int main() {
    Node* head = NULL;
    cout << "Enter a negative number to break : ";
    int n;
    cin >> n;

    Node* ptr = head;
    while(n > -1) {
        Node* tmp;
        tmp = getNode();
        if(tmp == NULL) {
            cout << "Insufficient space!!!\n";
            break;
        }
        tmp->data = n;
        tmp->next = NULL;
        if(head == NULL) {
            head = tmp;
            ptr = tmp;
        }
        else {
            ptr->next = tmp;
            ptr = ptr->next;
        }
        cin >> n;
    }

    ptr = head;
    while(ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;

    return 0;
}
