/*
https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D

Input: 
n, size of array
a1, ..., an an array of  numbers
k, number of queries
l, r, queries

Output: how many numbers have value within the boundary l and r inclusive

We make use of lower_bound (first elem >= k), upper_bound (first elem > k), and sort
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    // sort the array
    sort(a.begin(), a.end());

    int k; cin > k;
    while (k--) {
        int l, r;
        cin >> l >> r;
        int start = lower_bound(a.begin(), a.end(), l);
        int end = upper_bound(a.begin(), a.end(), r);
        cout << end - start << " ";
    }

    return 0;
}