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
  int n; cin  >> n;
  int a[100000]; int b[100000]; int c[100000];

  for (int i = 0; i < n; ++i) { cin >> a[i]; }
  for (int i = 0; i < n; ++i) { cin >> b[i]; }
  for (int i = 0; i < n; ++i) { cin >> c[i]; }

  sort(a, a+n);
  sort(b, b+n);
  sort(c, c+n);

  ll o = 0;

  ll cb[100000];
  for(int i = n-1;i>= 0;--i){
    int k = lower_bound(a, a+n, b[i])-a;
    cb[i] = k;
  }

  for (int i = 1; i < n; ++i) { cb[i] += cb[i-1]; }
  for (int i = n-1; i >= 0; --i) {
    int j = lower_bound(b, b+n, c[i])-b-1;
    if (j >= 0) o += cb[j];
  }
  std::cout << o << std::endl;

  return 0;
}

