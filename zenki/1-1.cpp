#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, count = 0;

    cin >> n;
    int S[n];
    for(int i=0; i<n; i++) cin >> S[i];
    cin >> q;
    int T[q];
    for(int i=0; i<q; i++) cin >> T[i];

    for(int i=0; i<q; i++) {
        int value = T[q];
        for(int j=0; j<n; j++) {
            if(value == S[j]) count++;
        }
    }

    cout << count << endl;
}