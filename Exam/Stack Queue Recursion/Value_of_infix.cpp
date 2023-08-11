#include<bits/stdc++.h>
using namespace std;

int topv = 0, topc = 0;

int pre(char ch) {
    if(ch == '(') return -1;
    else if(ch == '+' || ch == '-') return 0;
    else if(ch == '*' || ch == '/') return 1;
    else if(ch == '^') return 2;
}

int application(int a, int b, char ch) {
    switch(ch) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
    }
}

void pushc(char stk[], char ch) {
    stk[topc] = ch;
    topc++;
}
void pushv(int stk[], int val) {
    stk[topv] = val;
    topv++;
}

char popc(char stk[]) {
    topc--;
    return stk[topc];
}
int popv(int stk[]) {
    topv--;
    return stk[topv];
}

int calculate(string in) {
    in += ')';
    int v[10];
    char c[10];
    pushc(c, '(');
    int i = 0;
    while(topc != 0) {
        if(in[i] == ' ') {
            i++;
            continue;
        }
        if(in[i] == ')') {
            char ch = popc(c);
            while(ch != '(') {
                int x = popv(v);
                int y = popv(v);
                int ans = application(y, x, ch);
                pushv(v, ans);
                ch = popc(c);
            }
            i++;
            continue;
        }
        if(in[i] >= '0' && in[i] <= '9') {
            int x = in[i] - '0';
            i++;
            while(in[i] >= '0' && in[i] <= '9') {
                x *= 10;
                x += (in[i] - '0');
                i++;
            }
            pushv(v, x);
            continue;
        }
        else {
            if(in[i] == '(') {
                pushc(c, '(');
            }
            else {
                while(pre(c[topc-1]) > pre(in[i])) {
                    char ch = popc(c);
                    int x = popv(v);
                    int y = popv(v);
                    int ans = application(y, x, ch);
                    pushv(v, ans);
                }
                pushc(c, in[i]);
            }
            i++;
        }
    }
    return v[topv-1];
}

int main() {
    string infix = "5 * ( 6 + 2 ) - 8 / 4";
    //cout << "Please enter space separated values and characters (\"EX: 2 + ( 10 * 3 ) - 1\") : ";
    //cin >> infix;

    int result = calculate(infix);
    cout << infix << " = " << result << endl;

    return 0;
}
