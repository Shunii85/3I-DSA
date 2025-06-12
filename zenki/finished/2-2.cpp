#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
    if(n == 2) return true;

    // 2以外の偶数は排除
    if(n < 2 || n%2 == 0) return false;

    // 合成数は、その平方数以下の素因子をもつ性質
    int i = 3;
    while (i <= sqrt(n) + 1){
        if(n%i == 0) return false;
        i += 2;
    }
    return true;
}

int main() {
    int n, a[10000], count = 0;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    for(int i=0; i<n; i++){
        if(is_prime(a[i])) count++;
    }
    cout << count << endl;
}