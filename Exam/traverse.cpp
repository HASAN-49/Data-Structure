#include<iostream>
#include<math.h>
using namespace std;

int main() 
{
    // Deaclaration of an array
    int a[10] = {5, 7, 9, 4, 8, 10, 1, 2, 3, 6};

    // Searching the max value
    int mx = a[0];
    for(int i = 0; i < 10; i++) {
        if(a[i] > mx) mx = a[i];
    }
    cout << "Max value = " << mx << endl;

    // Searching the min value
    int mn = a[0];
    for(int i = 0; i < 10; i++) {
        if(a[i] < mn) mn = a[i];
    }
    cout << "Min value = " << mn << endl;

    // Calculating the average value and total value
    int total = 0.0;
    for(int i = 0; i < 10; i++) {
        total += a[i];
    }
    cout << "Average value = " << total/10.0 << endl;
    cout << "Total value = " << total << endl;

    // Sine value of array a
    for(int i = 0; i < 10; i++) {
        cout << "Sin vale of " << a[i] << " = " << sin(a[i]) << endl;
    }
}