#include<iostream>
#include<math.h>
using namespace std;

int main() 
{
    int n = 10, sz = 10;
    // Deaclaration of a sorted integer array
    int a[12] = {1, 14, 27, 30, 43, 56, 69, 72, 85, 98};
    // Declaration of a sorted string array
    string name[12] = {"Ali", "Amir", "Bashir", "Esan", "Hasan", "Jalal", "Kabir", "Liton", "Morshed", "Sojib"};

    // Inserting 54 
    int val = 54;
    for(int i = n; i >= 0; i--) {
        if(i == 0) {
            a[i] = val;
        }
        else if(a[i-1] > val) {
            a[i] = a[i-1];
        }
        else {
            a[i] = val;
            break;
        }
    }
    n += 1;
    // Display
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // Inserting Rokib
    string s = "Rokib";
    for(int i = sz; i >= 0; i--) {
        if(i == 0) {
            name[i] = s;
        }
        else if(name[i-1] > s) {
            name[i] = name[i-1];
        }
        else {
            name[i] = s;
            break;
        }
    }
    sz += 1;
    // Display
    for(int i = 0; i < sz; i++) {
        cout << name[i] << " ";
    }
    cout << endl;

    // Inserting 99 to position 5
    val = 99;
    for(int i = n; i >= 0; i--) {
        if(i >= 5) {
            a[i] = a[i-1];
        }
        else {
            a[i] = val;
            break;
        }
    }
    n += 1;
    // Display
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // Inserting Mahmudul to position 5
    s = "Mahmudul";
    for(int i = sz; i >= 0; i--) {
        if(i >= 5) {
            name[i] = name[i-1];
        }
        else {
            name[i] = s;
            break;
        }
    }
    sz += 1;
    // Display
    for(int i = 0; i < sz; i++) {
        cout << name[i] << " ";
    }
    cout << endl;
}