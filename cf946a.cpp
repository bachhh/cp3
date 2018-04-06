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
  int n; cin >> n;
  int v[101];

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  sort(v, v+n);
  int prefix[101];

  for (int i = 0; i < n; ++i) {
    prefix[i] = v[i];
    if(i>0) prefix[i] += prefix[i-1];
  }

  prefix[n] = 0;

  int maxt = prefix[n-1];
  for (int i = 1; i < n; ++i) {
    //std::cout << maxt << std::endl;
    maxt = max(maxt, prefix[n-1] - prefix[i-1]*2);
  }
  maxt = max(maxt, prefix[n] - prefix[n-1]);
  std::cout << maxt << std::endl;

  return 0;
}

