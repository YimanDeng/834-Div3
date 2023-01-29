// note to self: pay attetion to really dumb bugs such as:
//      confusing 1 with i
//      confusing = with ==
//      forget to comment out debugging print statements

#include<bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); i++)

const int LIM = 5e5+10;
int n, m;
int p[LIM], sz[LIM]; // parent array and size array

int find_root(int x) {
    return x == p[x] ? x : p[x] = find_root(p[x]);
}


void unite(int a, int b) {
    a = find_root(a);
    b = find_root(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
    }
}

int main(){
    cin >> n >> m;
    forn(i, n) p[i] = i, sz[i] = 1;
	
    forn(i, m) {
        int k; cin >> k;
        int last_friend = -1;
        forn(j, k) {
			int x;
			cin >> x;
			--x;
			if (last_friend != -1)
				unite(last_friend, x);
			last_friend = x;
		}
	}
	
	forn(i, n)
		printf("%d ", sz[find_root(i)]);
}
