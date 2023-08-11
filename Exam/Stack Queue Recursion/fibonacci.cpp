#include<bits/stdc++.h>
using namespace std;

long fib[1000];

long fibo_series(int n) {
    if(n == 0 || n == 1) {
        fib[n] = n;
    }
    else {
        fib[n] = fibo_series(n-2) + fibo_series(n-1);
    }
    return fib[n];
}

int main() {
    cout << "Press number 1 or 2\n";
    cout << "1. Fibonacci series.\n";
    cout << "2. See Fn of a fibonacci series.\n";

    int choice;
    cin >> choice;

    if(choice < 1 && choice > 2) {
        cout << "Wrong choice.....\n";
    }
    else {
        cout << "Enter the length/position : ";
        int n;
        cin >> n;
        fibo_series(n-1);
        if(choice == 1) {
            for(int i = 0; i < n; i++) {
                cout << fib[i] << " ";
            }
            cout << endl;
        }
        else {
            cout << fib[n-1] << endl;
        }
    }

    return 0;
}
