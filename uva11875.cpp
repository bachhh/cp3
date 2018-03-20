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

  for (int i = 1; i <= tc; ++i) {
    int n; cin >> n;

    int a[12];
    for (int j = 0; j < n; ++j) {
      cin >> a[j];
    }

    int t;
    if (n%2) t = a[n/2];
    else {
      t = (a[n/2] + a[n/2-1])/2;
    }

    printf("Case %d: %d\n", i, t);
  }

  return 0;
}

