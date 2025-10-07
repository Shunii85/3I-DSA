#include <bits/stdc++.h>
using namespace std;

int main() {
    string t, p;

    cin >> t >> p;

    int i = 0;
    int j = 0;
    while (i < t.size() && j < p.size()){
        if(t[i] == p[j]) {
            if(j == p.size() - 1) {
                i = i - j + 1;
                j = 0;
                cout << i - 1 << endl;
            } else {
                i++;
                j++;
            }
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
}