#include <bits/stdc++.h>
using namespace std;

void maxHeapify(int* A, int i, int H);
void buildMaxHeap(int* A, int H);

int main() {
  int H, A[500000];

  cin >> H;
  for (int i = 0; i < H; i++) {
    cin >> A[i];
  }

  buildMaxHeap(A, H);

  for (int i = 0; i < H; i++) {
    cout << " " << A[i];   
  }
  cout << endl;
}

void maxHeapify(int* A, int i, int H) {
  int l = 2*i + 1;
  int r = 2*i + 2;

  int largest;
  // 左の子と根を比べる
  if(l< H && A[l] > A[i]) {
    largest = l;
  } else {
    largest = i;
  }

  // 右の子と根を比べる
  if(r< H && A[r] > A[largest]) {
    largest = r;
  }

  if(largest != i) {
    int tmp = A[i];
    A[i] = A[largest];
    A[largest] = tmp;

    maxHeapify(A, largest, H);
  }
}

void buildMaxHeap(int* A, int H) {
  for (int i = (H-1)/2; i >= 0; --i) {
    maxHeapify(A, i, H); 
  }
}