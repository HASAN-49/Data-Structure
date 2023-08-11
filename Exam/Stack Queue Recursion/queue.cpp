#include<bits/stdc++.h>
using namespace std;

int MAX = 10;
int FRONT = -1, REAR = -1;

void q_insert(int q[], int value) {
    if(FRONT == 0 && REAR == MAX-1) {
        cout << "OVERFLOW...\n";
        return;
    }
    if(REAR + 1 == FRONT) {
        cout << "OVERFLOW...\n";
        return;
    }
    if(FRONT == -1) {
        FRONT += 1;
        REAR = FRONT;
    }
    else {
        REAR += 1;
        if(REAR == MAX) REAR = 0;
    }
    q[REAR] = value;
}

void q_delete(int q[]) {
    if(FRONT == -1) {
        cout << "UNDERFLOW...\n";
        return;
    }
    int item = q[FRONT];
    if(FRONT == REAR) {
        FRONT = -1;
        REAR = -1;
    }
    else {
        FRONT += 1;
        if(FRONT == MAX) FRONT = 0;
    }
}

void display(int q[]) {
    if(FRONT == -1) {
        cout << "No elements...\n";
        return;
    }
    for(int i = FRONT; i <= REAR; i++) {
        cout << q[i] << " ";
    }
    cout << endl;
}

int main() {
    int q[MAX];

    q_insert(q, 1);
    q_insert(q, 2);
    q_insert(q, 3);
    q_insert(q, 1);
    q_insert(q, 2);
    q_insert(q, 3);
    display(q);
    q_insert(q, 1);
    q_insert(q, 2);
    q_insert(q, 3);
    q_insert(q, 1);
    q_insert(q, 2);
    q_insert(q, 3);
    display(q);

    q_delete(q);
    q_delete(q);
    q_delete(q);
    q_delete(q);
    display(q);
    q_delete(q);
    q_delete(q);
    q_delete(q);
    q_delete(q);
    display(q);
    q_delete(q);
    q_delete(q);
    q_delete(q);
    q_delete(q);
    display(q);

    return 0;
}
