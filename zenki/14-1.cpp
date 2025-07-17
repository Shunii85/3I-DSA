#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define M 12/* your task*/
#define L 14

char H[M][L]; /* Hash Table */

int getChar(char ch){
  if ( ch == 'A') return 1;
  else if ( ch == 'C') return 2;
  else if ( ch == 'G') return 3;
  else if ( ch == 'T') return 4;
}

/* convert a string into an integer value */
ll getKey(char str[]){
  ll sum = 0, p = 1;
  for (ll i = 0; i < strlen(str); i++){
    sum += p*(getChar(str[i]));
    p *= 5;
  }
  return sum;
}

int h1(int key){ return key % M; }
int h2(int key){ return key % L; }

int find(char str[]){
    /* your task */
    ll m = h1(getKey(str));
    ll l = h2(getKey(str));

    return H[m][l];
}

int insert(char str[]){
    /* your task */
    ll m = h1(getKey(str));
    ll l = h2(getKey(str));

    while ()
    {
        /* code */
    }
    
}

int main(){
    int n, h;
    char str[L], com[9];
    for (int i = 0; i < M; i++ ) H[i][0] = '\0';
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++ ){
	    scanf("%s %s", com, str);
	
        if(com[0] == 'i'){
            insert(str);
        } else {
            if(find(str)){
                printf("yes\n");    
            } else {
                printf("no\n");
            }
        }
    }

    return 0;
}