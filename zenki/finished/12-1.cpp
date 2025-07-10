#include <bits/stdc++.h>
#define NMAX 100000
#define KMAX 200000
using namespace std;
int binarySearch(int a[], int n, int q);

int main() {
    int n, a[NMAX], q, k[KMAX];

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    cin >> q;
    for(int i=0; i<q; i++) {
        cin >> k[i];
    }

    for(int i=0; i<q; i++) {
        int index = binarySearch(a, n, k[i]);
        if(index != -1) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
}

int binarySearch(int a[], int n, int q) {
    int m;
    int l = 0;
    int r = n-1;

    // lとrが同じindexじゃないなら調べる
    while(l <= r) {
        m = (l + r)/2;

        if(a[m] == q) return m;
        if(a[m] > q) {
            r = m-1;
        } else {
            l = m+1;
        }
    };

    return -1;
}