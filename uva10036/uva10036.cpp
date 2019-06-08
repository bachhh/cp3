#include <bits/stdc++.h>

using namespace std;

#define LIMIT 10001

int n, k;

int v[LIMIT];
int memo[10001][101];

int solve(int i, int sum){
  if (i==0) return solve(i+1, (sum+v[i])%k);
  if (i==n) return sum%k == 0;

  int add = (sum+v[i]%k);
  int sub = ((sum-v[i])%k+k)%k;

  int addi = solve(i+1, add);
  int subi = solve(i+1, sub);

  if (memo[i][sum] != -1) return memo[i][sum];
  memo[i][sum] = addi || subi;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int tc; cin >> tc;

  while(tc--){

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      v[i] %= k;
    }
    for (int i = 0; i < LIMIT; i++) {
      for (int j = 0; j < 101; j++) {
        memo[i][j] = -1;
      }
    }

    if (solve(0, 0)){
      std::cout << "Divisible" << std::endl;
    }
    else{
      std::cout << "Not Divisible" << std::endl;
    }

  }


  return 0;
}

