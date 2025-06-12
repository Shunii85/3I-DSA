#include <bits/stdc++.h>
using namespace std;

int bubbleSort(int a[], int n);

int main() {
    int N, a[100];

    cin >> N;
    for(int i=0; i<N; i++) cin >> a[i];

    int counter = bubbleSort(a, N);

    for(int i=0; i<N; i++) {
        cout << a[i];
        if(i != N-1) cout << " ";
    }
    cout << endl;
    cout << counter << endl;
}

int bubbleSort(int a[], int n) {
    bool sorted = false;
    int counter = 0;
    int j = n - 1;

    while (!sorted){
        sorted = true;
        j--;
        for (int i=0; i<=j; i++){
            if(a[i]>a[i+1]) {
                swap(a[i], a[i+1]);
                counter++;
                sorted = false;
            }
        }
    }

    return counter;
}