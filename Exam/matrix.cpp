#include<iostream>
using namespace std;

int main()
{
    // Declaring 2 matrix
    int mat1[3][3] = {
        {2, 3, 4},
        {3, 2, 1},
        {1, 4, 3}
    };
    int mat2[3][3] = {
        {2, 3, 1},
        {3, 2, 4},
        {4, 1, 3}
    };

    // Addition
    int add[3][3];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            add[i][j] = mat1[i][j] + mat2[i][j]; 
        }
    }
    // Display
    cout << "Addition : \n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << add[i][j] << " ";
        }
        cout << endl;
    }

    // Subtraction
    int sub[3][3];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            sub[i][j] = mat1[i][j] - mat2[i][j]; 
        }
    }
    // Display
    cout << "Subtraction : \n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << sub[i][j] << " ";
        }
        cout << endl;
    }

    // Declaring another matri for multiplication
    int r1 = 3, c1 = 2, r2 = 2, c2 = 3;
    int a[r1][c1] = {
        {2, 3},
        {3, 2},
        {1, 4}
    };
    int b[r2][c2] = {
        {2, 3, 1},
        {3, 2, 4}
    };
    // Multiplication
    int m[r1][c2]; // r1 X c2 matrix will be produced
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            m[i][j] = 0;
            for(int k = 0; k < c1; k++) { // c1 = r2
                m[i][j] += a[i][k] * b[k][j];
            } 
        }
    }
    // Display
    cout << "Multiplication : \n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}