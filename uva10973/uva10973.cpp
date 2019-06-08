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

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int tc; cin >> tc;
  while(tc--){
    int n, m; cin >> n >> m;
    static int am[3001][3001];
    memset(am, 0, sizeof(am[0][0])*9006001);
    int x, y;
    for (int i = 0; i < m; ++i) {
      cin >> x >> y;
      am[x][y] = 1;
      am[y][x] = 1;
    }

    //std::cout << "TEST" << std::endl;
    int t = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = i+1; j <= n; ++j) {
        for (int k = j+1;am[i][j] && k <= n; ++k) {
          if(am[j][k] && am[k][i]){
            t++;
          }
        }
      }
    }

    std::cout << t << std::endl;
  }


  return 0;
}

