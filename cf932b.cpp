#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;

int dp[10][1000001];
int g[1000001];

int f(int n){
  int ret = 1;
  while(n> 0){
    if(n%10 ) ret *= n%10;
    n /= 10;
  }
  return ret;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int q;
  cin >> q;
  int l, r, k;


  for (int i = 1; i <= 1000000; ++i) {
    if(i < 10) g[i] = i;
    else g[i] = g[f(i)];
  }

  for (int i = 0; i < 10; ++i) {
    dp[i][0] = 0;
  }

  for (int i = 1; i <= 1000000; ++i) {
    for (int j = 0; j < 10; ++j) {
      if(g[i] == j){
        dp[j][i] = dp[j][i-1]+1 ;
      }
      else {
        dp[j][i] = dp[j][i-1];
      }
    }
  }



  for (int i = 0; i < q; ++i) {
    cin >> l >> r >>k;
    std::cout << dp[k][r] - dp[k][l-1] << std::endl;
  }

  return 0;
}

