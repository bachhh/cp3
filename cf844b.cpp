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
  int n, m; cin >> n >> m;
  int ma[50][50];
  memset(ma, 0, sizeof(ma[0][0] )*50*50);

  int sumroww[50] = {0};
  int sumrowb[50] = {0};
  int sumcolw[50] = {0};
  int sumcolb[50] = {0};
  for (int i = 0; i <n ; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> ma[i][j];
            if(ma[i][j] == 1){
                sumroww[i]++;
                sumcolw[j]++;
            }
            else {
                sumrowb[i]++;
                sumcolb[j]++;
            }
        }
  }

  ll t = 0;
  for (int i = 0; i < n; ++i) {
      t+= (ll(1)<<sumroww[i])-1;
      t+= (ll(1)<<sumrowb[i])-1;
  }

  for (int i = 0; i < m; ++i) {
      t+= (ll(1)<<sumcolw[i])-1;
      t+= (ll(1)<<sumcolb[i])-1;
  }

  std::cout << t-m*n << std::endl;

  return 0;
}

