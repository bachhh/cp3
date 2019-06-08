
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
  int tot = 0;
  int a[100003] = {0};

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    tot += abs(a[i]-a[i-1]);
  }

  tot+= abs(a[n]);

  for (int i = 1; i <= n; ++i) {
    std::cout << tot- abs(a[i]-a[i-1]) - abs(a[i+1]-a[i])+ abs(a[i+1]-a[i-1]) << std::endl;
  }

  return 0;
}

