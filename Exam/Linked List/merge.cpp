#include<bits/stdc++.h>
using namespace std;

typedef struct node Node;
struct node {
    int data;
    Node* next;
}*m, *list1, *list2;

Node* getNode() {
    Node* p;
    p = (Node*) malloc(sizeof(Node));
    return p;
}

void create1(int a[], int n) {
    Node* ptr = list1;
    for(int i = 0; i < n; i++) {
        Node* tmp = getNode();
        if(tmp == NULL) {
            cout << "Insufficient space...\n";
            return;
        }
        tmp->data = a[i];
        tmp->next = NULL;
        if(list1 == NULL) {
            list1 = tmp;
            ptr = tmp;
        }
        else {
            ptr->next = tmp;
            ptr = ptr->next;
        }
    }
}
void create2(int a[], int n) {
    Node* ptr = list2;
    for(int i = 0; i < n; i++) {
        Node* tmp = getNode();
        if(tmp == NULL) {
            cout << "Insufficient space...\n";
            return;
        }
        tmp->data = a[i];
        tmp->next = NULL;
        if(list2 == NULL) {
            list2 = tmp;
            ptr = tmp;
        }
        else {
            ptr->next = tmp;
            ptr = ptr->next;
        }
    }
}

void display(Node* head) {
    Node* tmp = head;
    while(tmp != NULL) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void merging() {
    m = NULL;
    Node *t1 = list1, *t2 = list2;
	Node *z = NULL;

	while(t1 != NULL){
		if(z == NULL){
			z = (Node*)malloc(sizeof(struct node));
			m = z;
		}
		else{
			z->next = (Node*)malloc(sizeof(struct node));
			z = z->next;
		}
		z->data = t1->data;
		t1 = t1->next;
	}

	while(t2 != NULL){
		if(z == NULL){
			z = (Node*)malloc(sizeof(struct node));
			m = z;
		}
		else{
			z->next = (Node*)malloc(sizeof(struct node));
			z = z->next;
		}
		z->data = t2->data;
		t2 = t2->next;
	}

	z->next = NULL;
}

int main() {
    int a[] = {6, 8 , 98, 23, 35, 27};
    int b[] = {12, 32, 65, 78, 91, 10};

    m = NULL, list1 = NULL, list2 = NULL;
    create1(a, sizeof(a) / sizeof(a[0]));
    create2(b, sizeof(b) / sizeof(b[0]));

    merging();
    cout << "Values of 1st list : ";
    display(list1);
    cout << "Values of 2nd list : ";
    display(list2);
    cout << "Values of merged list : ";
    display(m);

    return 0;
}
