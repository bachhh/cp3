#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100000

typedef pair<int, int> ii;
int n;
vector<int64_t> v;
vector<int64_t> range;

int dp[LIMIT][2];

int solve(int i, bool usable){

  //std::cout << v[i] << std::endl;
  // last beacon

  if(i == 0){ return dp[i][usable] =  usable; }
  if (i < 0) return 0;

  if (dp[i][usable] != -1){
    return dp[i][usable];
  }

  if (usable){

    // Search for the first activatable beacon to the left
    auto it = lower_bound(v.begin(), v.end(), v[i]-range[v[i]]);

    int index;
    if(it == v.end()){
      index =-1;
    }
    else {
      index = it - v.begin();
    }

    index--;


    if (index < 0){
      // no beacon left for activation
      return dp[i][usable] = 1;
    }
    else {
      // solve(this) = 1 + solve(next);
      return dp[i][usable] = 1 + solve(index, true);
    }
  }
  else {
    return dp[i][usable] = solve(i-1, true);
  }
}

//  ***** MAIN *****
int main(){
  //ios::sync_windexh_stdio(false);
  cin.tie(NULL);

  cin >> n;
  memset(dp, -1, sizeof(dp[0][0])*LIMIT*2);

  v.resize(n);
  range.resize(1000000);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    cin >> range[v[i]];
  }

  sort(v.begin(), v.end());


  // try turning off no beacon
  int max_avai = solve(n-1, true);

  // try turning off beacon one by one from the left
  // starting from  n-1 to 0
  for (int i = 1; i <= n; ++i){
    max_avai = max(solve(n-i, 0), max_avai);
  }
  std::cout << n-max_avai << std::endl;

  return 0;
}
