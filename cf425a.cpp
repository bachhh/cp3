#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;

int dp[210][3];
int n, k;
int a[200];

// Basic algorithm that start with a state
int solve(int i, int state){
  if (i == n){
    if (state){
      return 0;
    }
    return INT_MIN;
  }
  if (dp[i][state] != -1) return dp[i][state];
  int ret = INT_MIN;
  if (state == 0){
    // delay opening the interval
    ret = max(ret, solve(i+1, 1) + a[i]);
    // start the interval right here
    ret = max(ret, solve(i+1, 0));
  }
  if (state == 1){
    // continue interval;
    ret = max(ret, solve(i+1, 1)+a[i]);
    // stop interval right here
    ret = max(ret, solve(i+1, 2)+a[i]);
  }
  if(state == 2){
    ret = 0;
  }
  return dp[i][state] = ret;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;

  memset(dp, -1, sizeof(dp[0][0])*210*3);
  memset(a, 0, sizeof(a[0])*200);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout<<  solve(0, 0) << endl;

  return 0;
}

