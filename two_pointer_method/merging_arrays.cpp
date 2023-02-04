/*
This is the merge step of merge sort

So easy to get runtime error. Just initialize the size of the 
input and output arrays to make life easier.
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), out(n+m);

    for (int i=0; i < n; i++) cin >> a[i];
    for (int i=0; i < m; i++) cin >> b[i];

    int i = 0, j = 0, k = 0;

    while(i < n || j < m) {
        if (j == m || (i < n && a[i] < b[j]))  {
            out[k++] = a[i++];
        } else {
            out[k++] = b[j++];
        }
    }
    // or can append INF values to deal with when one ptr has advanced to end

    for (int c : out) {
        cout << c << " ";
    }

    cout << endl;

    return 0;
}
