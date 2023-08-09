#include<iostream>
using namespace std;

int main() 
{
    int sz = 10;
    // Declaration of a sorted string array
    string name[12] = {"Ali", "Amir", "Bashir", "Esan", "Hasan", "Jalal", "Kabir", "Liton", "Morshed", "Sojib"};

    // Deleting Hasan from an array
    string s = "Hasan";
    int pos = sz;
    for(int i = 0; i < sz; i++) {
        if(name[i] == s) {
            pos = i;
            break;
        }
    }
    for(int i = pos; i < sz-1; i++) {
        name[i] = name[i+1];
    }
    sz -= 1;
    // Display
    for(int i = 0; i < sz; i++) {
        cout << name[i] << " ";
    }
    cout << endl;

    // Delete from position 2
    pos = 2;
    for(int i = pos-1; i < sz-1; i++) {
        name[i] = name[i+1];
    }
    sz -= 1;
    // Display
    for(int i = 0; i < sz; i++) {
        cout << name[i] << " ";
    }
    cout << endl;
}