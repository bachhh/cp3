#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;

int dp[210][3][11][11];

int n, k;
int a[200];

// Basic algorithm that start with a state
int solve2(int i, int state, int in, int out){
  if (i == n){
    if (in == out && state != 0){
      return 0;
    }
    return -200010;
  }

  if (dp[i][state][in][out] > -200010)
    return dp[i][state][in][out];

  int ret = -200010;

  if (state == 0){
    // start the interval, or don't
    ret = max(solve2(i+1, 1, in, out) + a[i],
              solve2(i+1, 0, in, out));
    // start the interval, swap out this value
    ret = max(ret, solve2(i+1, 1, in+1, out));
    // don't start the interval but swap in this value
    if (out < k)
      ret = max(ret, solve2(i+1, 0, in, out+1)+a[i]);
  }

  if (state == 1){

    // continue interval, taking in, or swap out this value
    ret = max(ret, solve2(i+1, 1, in, out)+a[i]);
    if ( in < k )
      ret = max(ret, solve2(i+1, 1, in+1, out));

    // stop interval right here
    ret = max(ret, solve2(i+1, 2, in, out));
  }

  if(state == 2){

    // swap a value in from outside of interval
    if (out < k)
      ret = max(ret, solve2(i+1, 2, in, out+1)+a[i]);
    // or just ignore it
    ret = max(ret, solve2(i+1, 2, in, out));
  }

  return dp[i][state][in][out] = ret;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;

  for (int i = 0; i < 210; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 11; ++k) {
        for (int l = 0; l < 11; ++l) {
          dp[i][j][k][l] = -200010;
        }
      }
    }
  }

  memset(a, 0, sizeof(a[0])*200);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  cout<<  solve2(0, 0, 0, 0) << endl;

  return 0;
}

