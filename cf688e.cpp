#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

int n, k;
int c[510];
int dp[510][250000];

int solve(int i, int value){

  if (value ==  0){
    return dp[i][value] = 1;
  }
  if (i == n && value != 0){
    return 0;
  }

  if (dp[i][value] != -1) return dp[i][value];

  if(c[i] > value){
    return dp[i][value] = solve(i+1, value);
  }
  else{
    return dp[i][value] = solve(i+1, value) + solve(i+1, value - c[i]);
  }

}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  memset(dp, -1, sizeof(dp[0][0])*(n+1)*250000);

  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  sort(c, c+n);

  solve(0, k);
  vector<int> coinset;
  coinset.push_back(18);
  while(coinset.back() != 0){
    for (int i = 0; i < n; ++i) {
      if (dp[i][18] > 0){
      }
    }
  }



  return 0;

}

