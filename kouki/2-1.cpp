#include <bits/stdc++.h>
using namespace std;

void compf(string p, int f[]);

int main() {
    string text, pattern;
    int i, j;
    cin >> text;
    cin >> pattern;

    int* kmpNext = new int[pattern.size()];

    compf(pattern, kmpNext);
    
    i = 0;
    j = 0;
    while (){
        /* code */
    }
}


/**
 * @see https://daeudaeu.com/kmp/
 *
 * 失敗したとき、
 * その直前の部分文字列と
 * 先頭からの部分文字列が
 * 一致すれば
 * 次の比較はその部分を
 * 飛ばすことができる
 */
void compf(string p, int f[]) {
    f[0] = -1;
    f[1] = 0;

    for(int i=2; i<p.size(); i++) {
        // 1つ前の遷移先
        int j = f[i-1];

        // jが0以上じゃないと部分文字列は存在しない
        // p[i-1]とp[j]が一致しない場合、
        // より短い部分文字列を探す
        while(j>=0 && p[i-1] != p[j]) {
            // さらに小さい部分文字列を探す
            j = f[j];
        }

        f[i] = j+1;
    }
}