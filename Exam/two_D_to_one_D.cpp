#include<iostream>
#include<math.h>
using namespace std;

int main() 
{
    int a[4][5] = {{1, 2, 3, 4, 5},
                    {6, 7, 8, 9, 10},
                    {11, 12, 13, 14, 15},
                    {16, 17, 18, 19, 20}};

    int rowArray[20], colArray[20], r = 4, c = 5;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 5; j++) {
            rowArray[c*i+j] = a[i][j];
            colArray[r*j+i] = a[i][j];
        }
    }

    // Displaying row array
    for(int i = 0; i < 20; i++) {
        cout << rowArray[i] << " ";
    }
    cout << endl;

    // Displaying collumn array
    for(int i = 0; i < 20; i++) {
        cout << colArray[i] << " ";
    }
    cout << endl;

    // Displaying the 3rd group of the rowArray
    int k = c * (3-1);
    for(int i = k; i < k+c; i++) {
        cout << rowArray[i] << " ";
    }
    cout << endl;

    // Displaying the 3rd group of the collumn array
    k = r * (3-1);
    for(int i = k; i < k+r; i++) {
        cout << colArray[i] << " ";
    }
    cout << endl;
}