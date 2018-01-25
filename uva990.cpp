#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

int t, w, n;

int depth[30];
int worth[30];
int dp[30][1001];
vector<pair<int, int>> source;

int solve(int i, int air){
  if (i == n || air <= 0 ) return 0;
  if(dp[i][air] != -1 ) return dp[i][air];
  if (depth[i] > air){
    return dp[i][air] = solve(i+1, air);
  }

  return dp[i][air] = max(worth[i] + solve(i+1, air - depth[i]), solve(i+1, air));
}

string construct(int i, int t){
  if (i == n || t <= 0){
    return "";
  }
  if (dp[i][t] > 0 && dp[i][t] > dp[i+1][t]){
    return to_string((depth[i]/3)/w) + " " +
      to_string(worth[i]) + "\n" + construct(i+1, t - depth[i]);
  }
  else {
    return construct(i+1, t);
  }
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  while(cin >> t >> w){

    cin >> n;
    source.clear();

    for (int i = 0; i < n; i++) {
      cin >> depth[i] >> worth[i];
      depth[i] = depth[i]*3*w;
    }
    for (int i = 0; i < 30; i++) {
      for (int j = 0; j < 1001; j++) {
        dp[i][j] = -1;
      }
    }
    std::cout << solve(0, t) << std::endl;
    string output = construct(0, t);
    int s = 0;
    for (char c : output) { if (c=='\n') s++;}
    std::cout << s << std::endl;
    std::cout << output;

  }

  return 0;
}

