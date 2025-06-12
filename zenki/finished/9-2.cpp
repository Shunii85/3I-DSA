#include <bits/stdc++.h>
using namespace std;
int selectionSort(int a[], int n);

int main() {
    int N, a[100];
    cin >> N;

    for(int i=0; i<N; i++) cin >> a[i];

    int counter = selectionSort(a, N);

    for(int i=0; i<N; i++) {
        cout << a[i];
        if(i != N-1) cout << " ";
    }
    cout << endl;
    cout << counter << endl;
}

int selectionSort(int a[], int n) {
    int counter = 0;

    for(int i=0; i<n-1; i++) {
        int min_i = i;

        // 最小のインデックスを見つけ出す
        for (int j=i+1; j<n; j++){
            if(a[j]<a[min_i]) {
                min_i = j;
            }
        }

        // それと左からスワップしてく(最初は左端。
        // それが一番小さいから。どんどん右に詰めてくと)
        if(i != min_i) {
            swap(a[i], a[min_i]);
            counter++;
        }
    }

    return counter;
}