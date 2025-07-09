#include <bits/stdc++.h>
#define INFTY 2000000000
using namespace std;
void mergeSort(int a[], int left, int right);
void merge(int a[], int left, int mid, int right);

int counter = 0;

int main() {
    int n;
    cin >> n;
    int S[n];
    for(int i=0; i < n; i++) {
        cin >> S[i];
    }
    
    mergeSort(S, 0, n);

    for(int i=0; i < n; i++) {
        cout << S[i];
        if(i != n-1) cout << " ";
        else cout << endl;
    }

    cout << counter << endl;
}

void mergeSort(int a[], int left, int right) {
    if(left+1 < right) {
        int mid = (left + right)/2;
        mergeSort(a, left, mid);
        mergeSort(a, mid, right);
        merge(a, left, mid, right);
    }
}

void merge(int a[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;

    int* L = new int[n1 + 1];
    int* R = new int[n2 + 1];

    for(int i=0; i < n1; i++) {
        L[i] = a[left + i];
    }

    for(int i=0; i < n2; i++) {
        R[i] = a[mid + i];
    }
    L[n1] = INFTY;
    R[n2] = INFTY;

    for(int i=0, j=0, k=left; k < right; k++) {
        counter++;
        if(L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
    }

    delete[] L;
    delete[] R;
}