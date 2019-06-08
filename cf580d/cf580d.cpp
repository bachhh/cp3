#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

int n, m, k;

int64_t a[20];
int64_t dp[524290][20];
int64_t bonus[20][20];

int64_t solve(int bitmask, int prev, int total){

  if (total >= m) return 0;

  if(dp[bitmask][prev] != -1) return dp[bitmask][prev];

  int64_t mx = -1;
  for (int i = 1; i <= n; i++) {
    if( !(bitmask&(1<<i)) ){
      mx = max<int64_t>(mx, bonus[prev][i] + a[i] + solve((bitmask|(1<<i)), i, total+1));
      //if(bitmask == 0 && prev == 0 && total == 0){ std::cout << i << std::endl; }
    }
  }

  return dp[bitmask][prev] = mx;

}

//  ***** MAIN *****
int main(){

  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> k;

  memset(dp, -1, sizeof(dp[0][0])*524290*20);
  memset(bonus, 0, sizeof(bonus[0][0])*20*20);

  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int x, y;

  for (int i = 0; i < k; i++) {
    cin >> x >> y;
    cin >> bonus[x][y];
  }

  std::cout << solve(0, 0, 0) << std::endl;

  return 0;
}

