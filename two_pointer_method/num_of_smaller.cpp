/*
Given two sorted arrays, for each element of the second array, 
Find the number of elements in the first array strictly less than it.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), out(m);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int j=0; j<m; j++) cin >> b[j];

    int i = 0;

    for (int j=0; j<m; j++) {
        while (i < n && a[i] < b[j]) {i++;}
        out[j] = i;
    }

    for (int elem : out) {
        cout << elem << " ";
    } 

    return 0;
}
