#include <bits/stdc++.h>
using namespace std;
struct Card {
    int num = 0;
    char mark;
};
int partition(Card a[], int p, int r);
void quicksort(Card a[], int p, int r);
bool compare_by_num(const Card& a, const Card& b) {
    return a.num < b.num;
}

int main() {
    int n;
    cin >> n;
    vector<Card> b(n);
    Card a[n];

    for(int i=0; i<n; i++) {
        cin >> a[i].mark >> a[i].num;
        b[i].mark = a[i].mark;
        b[i].num = a[i].num;
    }
    quicksort(a, 0, n-1);
    stable_sort(b.begin(), b.end(), compare_by_num);

    int count = 0;
    for (int i=0; i<n; i++){
        if(a[i].mark != b[i].mark) {
            count++;
        }
    }
    if(count > 0) cout << "Not stable" << endl;
    else cout << "Stable" << endl;
    
    for(const Card& A : a) {
        if(A.num != 0) cout << A.mark << " " << A.num << endl;
    }
}

void quicksort(Card a[], int p, int r) {
    if(p < r) {
        int q = partition(a, p, r);
        quicksort(a, p, q-1);
        quicksort(a, q+1, r);
    }
}

int partition(Card a[], int p, int r) {
    int x = a[r].num;
    int i = p-1;
    for(int j=p; j<r; j++) {
        if(a[j].num <= x) {
            i++;
            swap(a[i], a[j]);
        }
    }
    // a[r]、ピボットを基準の場所にする。a[i+1]を境に左が基準より小さい、右が大きい状態になる。
    swap(a[i+1], a[r]);

    return i+1;
}