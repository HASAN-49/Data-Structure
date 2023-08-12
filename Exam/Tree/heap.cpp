/*This is a min heap, if we want to make it max heap, greater than sign will be replaced by less then sign*/
#include<bits/stdc++.h>
using namespace std;

#define MAX 100

void heapDelete(int a[], int n, int i) {
    int largest = i;
    int left = i * 2;
    int right = left + 1;
    if(left <= n && a[largest] > a[left]) {
        swap(a[largest], a[left]);
        heapDelete(a, n, left);
    }
    if(right <= n && a[largest] > a[right]) {
        swap(a[largest], a[right]);
        heapDelete(a, n, right);
    }
}

void delete_root(int a[], int &n) {
    a[1] = a[n];
    n -= 1;
    heapDelete(a, n, 0);
}

void heap(int a[], int n) {
    int parent = n / 2;
    int child = n;
    if(parent > 0 && a[parent] > a[child]) {
        swap(a[parent], a[child]);
        heap(a, parent);
    }
}

void Insert(int a[], int &n, int value) {
    n += 1;
    a[n] = value;
    heap(a, n);
}

void display(int a[], int n) {
    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[MAX] = {-1};
    int n = 0;

    Insert(a, n, 9);
    Insert(a, n, 99);
    Insert(a, n, 89);
    Insert(a, n, 97);
    Insert(a, n, 100);
    Insert(a, n, 8);
    Insert(a, n, 9);

    display(a, n);

    delete_root(a, n);
    display(a, n);

    return 0;
}
