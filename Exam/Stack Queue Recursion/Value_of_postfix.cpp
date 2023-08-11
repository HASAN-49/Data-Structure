#include<bits/stdc++.h>
using namespace std;

int top = 0;

void push(int stk[], int val) {
    stk[top] = val;
    top++;
}

int pop(int stk[]) {
    top--;
    int item = stk[top];
    return item;
}

int calculate(string s) {
    int stk[10], i = 0;
    while(s[i] != ')') {
        if(s[i] >= '0' && s[i] <= '9') {
            push(stk, s[i]-'0');
        }
        else {
            int x = pop(stk);
            int y = pop(stk);
            cout << x << " " << y << endl;
            if(s[i] == '+') {
                int sum = x + y;
                push(stk, sum);
            }
            else if(s[i] == '-') {
                int sub = y - x;
                push(stk, sub);
            }
            else if(s[i] == '*') {
                int m = x * y;
                push(stk, m);
            }
            else if(s[i] == '/') {
                int div = y / x;
                push(stk, div);
            }
            else {
                int pwr = pow(y, x);
                push(stk, pwr);
            }
        }
        i++;
        //cout << stk[top-1] << endl;
    }
    return stk[top-1];
}

int main() {
    string postfix = "562+*84/-";
    postfix += ')';
    cout << postfix << endl;

    int result = calculate(postfix);

    cout << "The ans is = " << result << endl;
}
