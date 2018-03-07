#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef int64_t ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  int c[500], s[500], f[500];

  for (int i = 0; i < n-1; ++i) {
    cin >> c[i] >> s[i] >> f[i];
  }

  for (int i = 0; i < n-1; ++i) {
    int t = 0;
    for (int j = i; j < n-1; ++j) {
      if(t< s[j]) t = s[j];
      else {
        t = ceil((t-s[j])/(double)f[j])*f[j] + s[j];
      }
      t += c[j];
    }
    std::cout << t << std::endl;
  }

  std::cout << 0 << std::endl;

  return 0;
}

