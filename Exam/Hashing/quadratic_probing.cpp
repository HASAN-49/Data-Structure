#include<bits/stdc++.h>
using namespace std;

int primes[101];
bool Prime() {
    primes[0] = primes[1] = 1;
    for(int i = 2; i * i < 100; i++) {
        if(primes[i] == 0) {
            for(int j = i * 2; j <= 100; j += i) primes[j] = 1;
        }
    }
}

int findPrime(int num) {
    while(primes[num] == 1) {
        num++;
    }
    return num;
}

void Insert(int a[], char c[], int n, int k) {
    cout << "Enter values : ";
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int m = x % k, new_m = x % k, tmp = 1;
        while(c[new_m] != 'f') {
            new_m = m + tmp * tmp; // m+1 --> m+1+3 = m + 4 --> m+1+3+5 = m+9
            new_m %= k;
            tmp += 1;
        }
        m = new_m;
        c[m] = 't';
        a[m] = x;
    }
}

void display(int a[], char c[], int k) {
    cout << "Hash table : ";
    for(int i = 0; i < k; i++) {
        if(c[i] == 'f') cout << "N ";
        else cout << a[i] << " ";
    }
    cout << endl;
}

void Search(int a[], char c[], int k, int item) {
    cout << "Position of the value : " ;
    int m = item % k, new_m = 0, tmp = 0;
    int cnt = k;
    while(cnt--) {
        new_m = m + tmp * tmp; // m+1 --> m+1+3 = m + 4 --> m+1+3+5 = m+9
        new_m %= k;
        tmp += 1;
        if(a[new_m] == item) {
            cout << new_m + 1 << endl;
            return;
        }
    }
    cout << "This value is not present in the hash table.\n";
}

// TEST : 54 26 93 17 77 31 44 55 20
int main() {
    Prime();
    cout << "Enter the number of values : ";
    int n;
    cin >> n;
    int k = findPrime(n);

    int h[k];
    char c[k];
    for(int i = 0; i < k; i++) c[i] = 'f';

    Insert(h, c, n, k);
    display(h, c, k);
    Search(h, c, k, 0);
    Search(h, c, k, 55);

    return 0;
}

