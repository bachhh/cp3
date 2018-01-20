#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

int m;
int total;
int v[LIMIT];
int memo[100][501];

int solve(int coin, int weight){
  if (weight <= 0) return 0;
  if (coin == m) return 0;

  if (memo[coin][weight] != -1) return memo[coin][weight];
  if (v[coin] > weight){
    return solve(coin+1, weight);
  }
  else {
    return max(solve(coin+1, weight), v[coin] + solve(coin+1, weight-v[coin]+1));
  }
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int tc; cin >> tc;
  while(tc--){
    cin >> m;
    total = 0;

    for (int i = 0; i < m; i++) {
      cin >> v[i];
      total += v[i];
    }


  }


  return 0;
}

