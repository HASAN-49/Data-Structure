#include<bits/stdc++.h>
using namespace std;

void tower(int n, char start, char mid, char destination) {
    if(n == 1) {
        cout << start << "-->" << destination << endl;
        return;
    }
    tower(n-1, start, destination, mid);
    cout << start << "-->" << destination << endl;
    tower(n-1, mid, start, destination);
}

int main() {
    cout << "Enter the number of disk : ";
    int n;
    cin >> n;

    tower(n, 'A', 'B', 'C');

    return 0;
}
