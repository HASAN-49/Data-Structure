/*1. Find out the Path Matrix of an adjacent matrix with m nodes using Warshall’s Algorithm.

2. Find out the shortest path of a Weighted Graph G with m nodes V1, V2, … ,Vm and weight
of each edge is w(e) using Warshall’s Algorithm.

7 5 0 0
7 0 0 2
0 3 0 0
4 0 1 0

*/

#include<iostream>
#include<climits>
using namespace std;

const unsigned int m = 4, mx = INT_MAX;

int main() {
    unsigned int a[m][m], p[m][m], sp[m][m]; // p = path, sp = shortest path

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 0) {
                p[i][j] = 0;
                sp[i][j] = mx;
            }
            else {
                p[i][j] = 1;
                sp[i][j] = a[i][j];
            }
        }
    }

    // Warshall's Algorithm
    for(int k = 0; k < m; k++) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                p[i][j] = p[i][j] | (p[i][k] & p[k][j]);
            }
        }
    }

    cout << "Path matrix : \n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }

    // Warshall's Algorithm for shortest path
    for(int k = 0; k < m; k++) {
        cout << "Value after " << k << " operation(s) : \n";
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                if(sp[i][j] == mx) cout << "IN ";
                else cout << sp[i][j] << " ";
            }
            cout << endl;
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                unsigned int tmp = sp[i][k] + sp[k][j];
                if(tmp < sp[i][j]) sp[i][j] = tmp;
            }
        }
    }

    cout << "Shortest path after all(m) operations : \n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            if(sp[i][j] == mx) cout << "INF ";
            else cout << sp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
