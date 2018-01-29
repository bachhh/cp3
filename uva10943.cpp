#include <bits/stdc++.h>

using namespace std;

#define LIMIT 1000000

int n, k;
int64_t dp[101][101];

int64_t solve(int sum, int counter){
  if (dp[sum][counter] != -1) return dp[sum][counter];
  if( counter == 1){
    return 1;
  }

  int64_t output = 0;
  for (int i = 0; i <= sum; i++) {
    output += solve(sum - i, counter-1);
    if( output >LIMIT) output -= LIMIT;
  }
  return dp[sum][counter] = output;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 0; i < 101; i++) {
    for (int j = 0; j < 101; j++) {
      dp[i][j] = -1;
    }
  }

  while(cin >> n >> k && n && k){
    std::cout << solve(n, k)%1000000 << std::endl;
  }

  return 0;
}

