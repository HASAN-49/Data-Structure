#include<bits/stdc++.h>
using namespace std;

int top = 0;

void push(char stk[], char ch) {
    stk[top] = ch;
    top++;
}

char pop(char stk[]) {
    top--;
    char item = stk[top];
    return item;
}

int pre(char ch) {
    if(ch == '(') return -1;
    else if(ch == '+' || ch == '-') return 0;
    else if(ch == '*' || ch == '/') return 1;
    else if(ch == '^') return 2;
}

string infix_to_postfix(string s) {
    char stk[10];
    string post = "";
    int i = 0;
    push(stk, '(');
    s += ')';
    while(top > 0) {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            post += s[i];
        }
        else if(s[i] == ')') {
            char ch = pop(stk);
            while(ch != '(') {
                post += ch;
                ch = pop(stk);
            }
        }
        else {
            int v1 = pre(s[i]);
            if(v1 == -1) {
                push(stk, s[i]);
            }
            else {
                while(pre(stk[top-1]) > v1) {
                    char ch = pop(stk);
                    post += ch;
                }
                push(stk, s[i]);
            }
        }
        i++;
        //cout << s << endl;
        //cout << post << endl;
    }
    return post;
}

int main() {
    string infix = "A+(B*C-(D/E^F)+G)*H";
    //cin >> infix;
    cout << "INFIX : " << infix << endl;

    string postfix = infix_to_postfix(infix);
    cout << "POSTFIX : " << postfix << endl;

    return 0;
}
