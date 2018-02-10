#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
#define MOD 1000000007
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  int64_t dp[1000];
  vector<string> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  for (int i = 0; i < m; ++i) {
    set<char, greater<char>> st;
    st.insert(v[0][i]);

    for (int j = 1; j < n; j++) {
      st.insert(v[j][i]);
    }
    int diff = st.size();
    diff %= MOD;
    dp[i] = diff * (i>0?dp[i-1]:1);
    dp[i] %= MOD;
  }

  std::cout << dp[m-1] << std::endl;

  return 0;
}

