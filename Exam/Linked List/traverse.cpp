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

void traverse(Node* head) {
    int mx, mn, cnt = 0, sum = 0;
    Node* tmp = head;
    cout << "Sin values : \n";
    while(tmp != NULL) {
        cnt += 1;
        int x = tmp->data;
        tmp = tmp->next;
        if(cnt == 1) {
            mx = x;
            mn = x;
        }
        else {
            if(x > mx) mx = x;
            if(x < mn) mn = x;
        }
        sum += x;
        cout << "\t->Sin value of " << x << " = " << sin(x) << endl;
    }
    cout << "Maximum value = " << mx << endl;
    cout << "Minimum value = " << mn << endl;
    cout << "Sumation = " << sum << endl;
    cout << "Average = " << (sum * 1.0) / cnt << endl;
}

int main() {
    Node* head = NULL;
    int a[] = {5, 3, 9, 42, 0, 10};
    int n = sizeof(a) / sizeof(a[0]);

    Node* ptr = head;
    for(int i = 0; i < n; i++) {
        Node* tmp;
        tmp = getNode();
        if(tmp == NULL) {
            cout << "Insufficient space!!!\n";
            break;
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

    traverse(head);

    return 0;
}