#include <bits/stdc++.h>
using namespace std;
int partition(int a[], int p, int r);

int main() {
    int n, A[100000];
    cin >> n;
    for(int i=0; i<n; i++) cin >> A[i];

    int x = partition(A, 0, n-1);

    for(int i=0; i<n; i++) {
        if(i == x) {
            cout << "[" << A[i] << "]";
        } else cout << A[i];

        if(i != n-1) cout << " ";
    }
    cout << endl;
}

int partition(int a[], int p, int r) {
    int x = a[r];
    int i = p-1;
    for(int j=p; j<r; j++) {
        if(a[j] <= x) {
            i++;
            swap(a[i], a[j]);
        }
    }
    // a[r]、ピボットを基準の場所にする。a[i+1]を境に左が基準より小さい、右が大きい状態になる。
    swap(a[i+1], a[r]);

    return i+1;
}