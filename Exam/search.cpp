#include<iostream>
#include<math.h>
using namespace std;

int main() 
{
    int n = 10, sz = 10;
    // Deaclaration of a sorted integer array
    int a[10] = {1, 14, 27, 30, 43, 56, 69, 72, 85, 98};
    // Declaration of a sorted string array
    string name[10] = {"Ali", "Amir", "Bashir", "Esan", "Hasan", "Jalal", "Kabir", "Liton", "Morshed", "Sojib"};

    // Searching 77 from an integer array
    int pos = -1, beg = 0, fin = n-1, item = 77;
    while(beg <= fin) {
        int mid = (beg + fin) / 2;
        if(a[mid] > item) {
            fin = mid - 1;
        }
        else if(a[mid] < item) {
            beg = mid + 1;
        }
        else {
            pos = mid + 1;
            break;
        }
    }
    if(pos == -1) cout << item << " not found!!!" << endl;
    else cout << item << " found at positn " << pos << endl;

    // Searching Kabir from a string array
    pos = -1, beg = 0, fin = sz-1;
    string tmp = "Kabir";
    while(beg <= fin) {
        int mid = (beg + fin) / 2;
        if(name[mid] > tmp) {
            fin = mid - 1;
        }
        else if(name[mid] < tmp) {
            beg = mid + 1;
        }
        else {
            pos = mid + 1;
            break;
        }
    }
    if(pos == -1) cout << tmp << " not found!!!" << endl;
    else cout << tmp << " found at positn " << pos << endl;
}