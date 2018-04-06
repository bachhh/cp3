#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
#define PLIMIT 10000010
#define MOD 1000000007ll
#define INF 1e9
typedef long long ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};


int dp[500][501];
int mh[500][501];
//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, k;
  cin >> n >> m >> k;

  memset(dp, 0, sizeof(dp[0][0])*500*501);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      mh[i][j] = m;
    }
  }


  string v[5000];
  int sum = 0;

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    for (int x = 0; x <= m ; ++x) {
      int k = 0;
      for (int y = x; y <= m; ++y) {
        if(v[i][y]=='1'){ k++; }
        mh[i][k] = min(mh[i][k], y-x+1);
      }
    }
  }

  for (int i = 0; i <= k; ++i) {
    dp[0][i] = mh[0][m-k];
  }

  for (int i = 0; i < n-1; ++i) {
    for (int j = 0; j <= k; ++j) {
      for (int l = 0; l <= k; ++l) {
        dp[i+1][j+l] = dp[i][j] + mh[i+1][l];
      }
    }
  }

  return 0;
}

