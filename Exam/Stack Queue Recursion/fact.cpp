#include<bits/stdc++.h>
using namespace std;

long long fact(int num) {
    if(num == 0 || num == 1) return 1;
    return num * fact(num-1);
}

int main() {
    int num, sign;
    cout << "Enter a number : ";
    cin >> num;

    int absnum = abs(num);
    if(num >= 0) sign = 1;
    else sign = -1;

    if(absnum > 20) {
        cout << "Overflow!!!\n";
    }
    else {
        long long int ans = fact(absnum);
        ans *= sign;
        cout << "Factorial of " << num << " is = " << ans << endl;
    }

    return 0;
}
