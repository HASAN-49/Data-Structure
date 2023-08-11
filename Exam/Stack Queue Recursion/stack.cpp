// push and deletion in stack
#include<bits/stdc++.h>
using namespace std;

#define MAX 10
int top = 0;

void push(int stk[], int value) {
    if(top == MAX) {
        cout << "Stack Overflow!!!\n";
        return;
    }
    stk[top] = value;
    top += 1;
    //return top;
}

void pop(int stk[]) {
    if(top == 0) {
        cout << "Stack Underflow!!!\n";
        return;
    }
    int item = stk[top-1];
    top--;
}

void display(int stk[]) {
    if(top == 0) cout << "No elements...\n";
    for(int i = 0; i < top; i++) {
        cout << stk[i] << " ";
    }
    cout << endl;
}

int main() {
    int stk[MAX];

    push(stk, 1);
    push(stk, 2);
    push(stk, 1);
    push(stk, 2);
    push(stk, 1);
    push(stk, 2);
    push(stk, 1);
    push(stk, 2);
    push(stk, 1);
    push(stk, 2);
    push(stk, 1);
    push(stk, 2);

    cout << "Elements on stack after push : ";
    display(stk);

    pop(stk);
    pop(stk);
    pop(stk);
    pop(stk);
    pop(stk);
    pop(stk);
    pop(stk);
    cout << "After some elements deleted : ";
    display(stk);
    pop(stk);
    pop(stk);
    pop(stk);
    pop(stk);
    pop(stk);

    cout << "After some more deletion : ";
    display(stk);

    return 0;
}
