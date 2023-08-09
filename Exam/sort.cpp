#include<iostream>
#include<math.h>
using namespace std;

int main() 
{
    // Deaclaration of an array
    int a[10] = {5, 7, 9, 4, 8, 10, 1, 2, 3, 6};
    int n = sizeof(a)/sizeof(a[0]);
    //cout << n << endl;

    // Bubble sort
    for(int i = 0; i < n-1; i++) {
        bool swapped = false;
        for(int j = 0; j < n-i-1; j++) {
            if(a[j] > a[j+1]) {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                swapped = true;
            }
        }
        if(!swapped) break;
    }
    //Display
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // Deaclaration of a string array
    string name[10] = {"RU", "JU", "DU", "CU", "BUET", "RUET", "KUET", "CUET", "NSTU", "IUT"};
    n = sizeof(name)/sizeof(name[0]);
    //cout << n << endl;

    // Bubble sort
    for(int i = 0; i < n-1; i++) {
        bool swapped = false;
        for(int j = 0; j < n-i-1; j++) {
            if(name[j] > name[j+1]) {
                string tmp = name[j];
                name[j] = name[j+1];
                name[j+1] = tmp;
                swapped = true;
            }
        }
        if(!swapped) break;
    }
    //Display
    for(int i = 0; i < n; i++) {
        cout << name[i] << " ";
    }
    cout << endl;
}