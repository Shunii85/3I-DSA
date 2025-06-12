#include <bits/stdc++.h>
using namespace std;

int gcd(int m, int n) {
    if(n==0) return m;
    return gcd(n, m%n);
}

int main() {
    int x, y;
    cin >> x >> y;

    cout << gcd(x, y) << endl;
}