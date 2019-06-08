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
    int n; cin >> n;
    int v[100000];
    int t = -1;

    cin >> v[0];
    int maxsen = v[0];
    for (int i = 1; i < n; ++i) {
      cin >> v[i];
      t = max(t, maxsen - v[i]);
      maxsen = max(v[i], maxsen);
    }

    std::cout << max(-1, t) << std::endl;

  }


  return 0;
}

