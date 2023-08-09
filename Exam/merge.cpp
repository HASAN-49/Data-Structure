#include<iostream>
#include<math.h>
using namespace std;

int main() 
{
    // Deaclaration of a sorted integer array
    int a[10] = {1, 14, 27, 30, 43, 56, 69, 72, 85, 98};
    int b[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);
    int n = n1 + n2;
    // Declaration of a sorted string array
    string name[10] = {"Ali", "Amir", "Bashir", "Esan", "Hasan", "Jalal", "Kabir", "Liton", "Morshed", "Sojib"};
    string name2[10] = {"Ali", "Amir", "Bashir", "Esan", "Hasan", "Jalal", "Kabir", "Liton", "Morshed", "Sojib"};
    int sz1 = sizeof(name) / sizeof(name[0]);
    int sz2 = sizeof(name2) / sizeof(name2[0]);
    int sz = sz1 + sz2;

    // adding two integer array
    int ab[n], j;
    for(j = 0 ; j < n1; j++) {
        ab[j] = a[j];
    }
    for(j = 0 ; j < n2; j++) {
        ab[j+n1] = b[j];
    }
    // Display
    for(int i = 0; i < n; i++) {
        cout << ab[i] << " ";
    }
    cout << endl;

    // adding two string array
    string mergerd_name[sz];
    for(j = 0 ; j < sz1; j++) {
        mergerd_name[j] = name[j];
    }
    for(j = 0 ; j < sz2; j++) {
        mergerd_name[j+n1] = name2[j];
    }
    // Display
    for(int i = 0; i < sz; i++) {
        cout << mergerd_name[i] << " ";
    }
    cout << endl;
}