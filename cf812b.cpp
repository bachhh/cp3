#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
#define LM 0
#define RM 1

int n, m;
int lr[15][2];
int dp[15][2];
int highest;

// The minimum time of solving 1 floor is
// the min time solving that floor from col
// + min time solving next floor from next col

int solve(int row, int col){
  if (row>highest) return 0;

  if (dp[row][col] != -1) return dp[row][col];

  if (row == highest){
    if (col == LM ){
      return dp[row][col] = lr[row][RM];
    }
    else if(col == RM){
      return dp[row][col] = m+1 - lr[row][LM];
    }
  }

  if (col == LM){
    int mi = lr[row][RM];
    if (lr[row][RM] != -1){
      mi += min( m+1 - lr[row][RM] + 1 + solve(row+1, RM),
          lr[row][RM] + 1 + solve(row+1, LM) );
    }
    else {
      mi = 1 + solve(row+1, col);
    }
    return dp[row][col] = mi;
  }
  else if(col == RM){
    int mi = m+1 - lr[row][LM];
    if(lr[row][LM] != -1){
      mi += min( lr[row][LM] + 1 + solve(row+1, LM),
          m+1-lr[row][LM] + 1 + solve(row+1, RM) );
    }
    else{
      mi = 1 + solve(row+1, col);
    }
    return dp[row][col] = mi;

  }
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  char matrix[15][110];
  for (int i = 0; i < 15; i++) {
    lr[i][LM] = -1;
    lr[i][RM] = -1;
    dp[i][LM] = -1;
    dp[i][RM] = -1;
  }
  highest = -1;

  char temp;
  for (int i = n-1; i >= 0; --i) {
    for (int j = 0; j < m+2; j++) {
      cin >> temp;

      if(temp == '1'){
        if (highest == -1) highest = i;
        if (lr[i][LM] == -1){
          lr[i][LM] = j;
        }
        lr[i][RM] = j;
      }
    }
  }

  std::cout << solve(0, LM) << std::endl;

  return 0;
}

