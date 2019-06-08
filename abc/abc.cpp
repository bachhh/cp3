#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
#define MOD 1000000007ll
#define INF 1e9
typedef long long ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

//  ***** MAIN *****
int main(){

  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  int a[200000];
  int b[200000];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  int t = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      t ^= a[i] + b[j];
    }
  }

  std::cout << a[0] << std::endl;

  return 0;
}

