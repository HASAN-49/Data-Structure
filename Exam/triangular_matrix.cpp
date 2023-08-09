#include<iostream>
using namespace std;

int main()
{
    // Declaration
    int A[5][5] = {
        {1, 0, 0, 0, 0},
        {2, 3, 0, 0, 0},
        {4, 5, 6, 0, 0},
        {7, 8, 9, 10, 0},
        {11, 12, 13, 14, 15}
    };

    // Counting non-zero elements
    int cnt = 0;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(A[i][j] != 0) cnt++;
        }
    }

    // Creating a linear array
    int B[cnt], k = 0;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(A[i][j] != 0) {
                B[k] = A[i][j];
                k++;
            }
        }
    }

    // Location of A[3][2] in B
    int com = (2 * 3) / 2;
    int loc = com + 2; // Location = 5
    cout << "A[3][2] = " << A[2][1] << ", B[loc-1] = " << B[loc-1] << endl;

    // print the elements of row 4
    int st = (4 * 3) / 2; // starting location
    int fi = st + 4; // ending location
    cout << "Element of 4th row : ";
    for(int i = st; i < fi; i++) {
        cout << B[i] << " ";
    }
    cout << endl;
}