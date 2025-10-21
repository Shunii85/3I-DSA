#include <bits/stdc++.h>
using namespace std;

// int main() {
//     int n, q;
//     cin >> n;

//     int A[n];
//     for(int i=0; i<n; i++) {
//         cin >> A[i];
//     }

//     cin >> q;
//     int m[q];
//     for(int i=0; i<q; i++) {
//         cin >> m[i];
//     }

// }

void print(int S[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++){
        cout << S[i] << ", ";
    }
    cout << "]" << endl;
}

void rec(int i, int S[], int n) {
    if(i == n) {
        print(S, n);
        return;
    }

    rec(i+1, S, n);
    S[i] = 1;
    rec(i+1, S, n);
    S[i] = 0;
}

void make_combination(int S[], int n){
    for (int i = 0; i < n; i++){
        S[i] = 0;
    }
    rec(0, S, n);
}


int main() {
    int n=3;
    int S[n];
    make_combination(S, n);
}
