#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007



int64_t factorial( int64_t x, int64_t accum = 1){
  if (x == 0 ) return 0;
  if (x == 1) return accum%MOD;
  return factorial(x-1, (accum*x)%MOD);
}

int64_t dp[1000000][1000000];

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  for (int _n = 0; _n <= n; ++_n) {
    for (int _k = 0; _k <= k; ++_k) {
      if (_k >= _n ){
        dp[_n][_k] = 0;
      }
      else{
        dp[_n][_k] = 1;
      }
    }
  }
  return 0;
}

