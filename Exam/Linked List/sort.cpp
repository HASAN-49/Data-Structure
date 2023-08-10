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

void sorting(Node* &head, int n) {
    if(head == NULL || head->next == NULL) {
        return;
    }
    Node* condition = head;
    while(condition != NULL) {
        condition = condition->next;
        Node* current = head->next;
        Node* previous = head;
        Node* bk = NULL;
        while(current != NULL) {
            if(current->data < previous->data) {
                /* p -> cn
                   c -> p
                   bk -> c
                */
                previous->next = current->next;
                current->next = previous;
                if(previous == head) {
                    head->next == current;
                    head = current;
                }
                else {
                    bk->next = current;
                }
            }
            bk = previous;
            previous = current;
            current = current->next;
        }
    }
}

int main() {
    int a[] = {5, 3, 9, 42, 0, 10};
    int n = sizeof(a) / sizeof(a[0]);

    Node* head;
    head = NULL;
    create(head, a, n);
    cout << "Before sorted : ";
    display(head);

    cout << "After sorted : ";
    sorting(head, n);
    display(head);

    return 0;
}

