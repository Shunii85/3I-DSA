// グラフ構造の隣接リストを、隣接行列にする
#include <bits/stdc++.h>
using namespace std;

int main() {
    int u, k, v, n;
    bool a[100][100] = {0};

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> u;
        cin >> k;
        for(int j=0; j<k; j++){
            cin >> v;
            a[u-1][v-1] = 1;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << a[i][j];
            if(j != n-1) cout << " ";
        }
        cout << endl;
    }
}