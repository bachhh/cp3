#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

int s, n;
int64_t memo[2][66][66];

int64_t solve(bool isLocked, int rem, int require){

  if ( require > rem ) return 0;
  if ( require == rem && !isLocked ) return 0;

  if (rem == 1){
    if (require == 0 && isLocked ) return 1;
    if (require == 0 && !isLocked) return 2;
    if (require == 1 && isLocked ) return 1;
    return 0;
  }

  if (memo[isLocked][rem][require] != -1) return memo[isLocked][rem][require];
  if(isLocked){
    memo[isLocked][rem][require] =
      solve(true, rem-1, require-1) + solve(false, rem-1, require);
  }
  else {
    memo[isLocked][rem][require] =
      solve(true, rem-1, require) + solve(false, rem-1, require);
  }

  return memo[isLocked][rem][require];
}

int dp[66][66];
//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(cin >> n >> s && s >= 0 && n >= 0){
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 66; j++) {
        for (int k = 0; k < 66; ++k) {
          memo[i][j][k] = -1;
        }
      }
    }
    std::cout << solve(true, n, s) << std::endl;
  }

  return 0;
}

