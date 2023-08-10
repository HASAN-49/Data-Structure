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

void deleteAnElement(Node* &head, int a[], int item) {
    if(head == NULL) {
        cout << "There is no element to delete\n";
        return;
    }
    if(head->data == item) {
        Node* tmp = head;
        head = head->next;
        free(tmp);
        return;
    }
    Node* current = head;
    Node* previous = NULL;
    Node* tmp;
    while(current != NULL) {
        if(current->data == item) {
            tmp = current;
            previous->next = current->next;
            free(tmp);
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << item << " was not found in the list\n";
}

void deleteAt(Node* &head, int a[], int pos) {
    if(head == NULL) {
        cout << "There is no element to delete\n";
        return;
    }
    if(pos == 1) {
        Node* tmp = head;
        head = head->next;
        free(tmp);
        return;
    }

    Node* current = head;
    Node* previous = NULL;
    Node* tmp;
    int cnt = 0;
    while(current != NULL) {
        cnt++;
        if(cnt == pos) {
            tmp = current;
            previous->next = current->next;
            free(tmp);
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "Position " << pos << "th was not available in the list\n";
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 8, 7};
    int n = sizeof(a) / sizeof(a[0]);
    Node* head;
    head = NULL;
    create(head, a, n);
    cout << "After creating a node : ";
    display(head);

    // Deleting
    deleteAnElement(head, a, 12);
    deleteAnElement(head, a, 1);
    deleteAnElement(head, a, 8);
    cout << "After deleting : ";
    display(head);

    deleteAt(head, a, 15);
    deleteAt(head, a, 5);
    display(head);

    return 0;
}
