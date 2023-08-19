/*1. Write a program that takes an Adjacent matrix A with m vertices as input and output the
following:
    a) adjacent of V1, V2,.................,Vm
    b) no. of paths of length 2 from Vi to Vj.
    c) no. of paths of length 3 from Vi to Vj.
    d) no. of paths of length 4 from Vi to Vj.

2. Take adjacency matrix with m nodes as input and calculate Br and from that calculate
Path Matrix and tell whether the matrix is strongly connected or not.

    0 0 0 1
    1 0 1 1
    1 0 0 1
    0 0 1 0

*/


#include<iostream>
using namespace std;

const int m = 4;

void adjacency_test(int a[][m][m]) {
    for(int i = 0; i < m; i++) {
        cout << "Adjacent of vertex " << i+1 << " : ";
        for(int j = 0; j < m; j++) {
            if(a[0][i][j] == 1) cout << j+1 << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void show_lenght(int a[][m][m], int length) {
    cout << "Numbers of paths of length " << length << " : \n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            cout << "Vertex " << i + 1 << " to Vertex " << j + 1 << " : " << a[length-1][i][j] << "\n";
        }
    }
    cout << endl;
}

void paths(int a[][m][m], int b[][m][m]) {
    for(int i = 1; i < m; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < m; k++) {
                a[i][j][k] = 0;
                for(int c = 0; c < m; c++) {
                    a[i][j][k] += (a[i-1][j][c] * a[0][c][k]);
                }
                b[i][j][k] = a[i][j][k] + b[i-1][j][k];
            }
        }
    }
}

void path_matrix(int b[][m][m], int p[][m], int *c) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            if(b[m-1][i][j] == 0) p[i][j] = 0;
            else p[i][j] = 1;
            *c += p[i][j];
        }
    }
}

void show_path_matrix(int p[][m]) {
    cout << "The path matrix is : \n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int a[m][m][m], b[m][m][m], p[m][m], connected = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[0][i][j];
            b[0][i][j] = a[0][i][j];
        }
    }

    adjacency_test(a);
    paths(a, b);
    show_lenght(a, 2);
    show_lenght(a, 3);
    show_lenght(a, 4);
    path_matrix(b, p, &connected);
    show_path_matrix(p);
    if(connected == m * m) cout << "\nTHE MATRIX IS STRONGLY CONNECTED\n";
    else cout << "\nTHE MATRIX IS NOT STRONGLY CONNECTED\n";

    return 0;
}
