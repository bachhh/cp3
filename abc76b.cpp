
#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef long long ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k; cin >> n >> k;
  int a = 1;

  for (int i = 0; i < n; ++i) {
    if(k<a) a+=k;
    else a+=a;
  }

  std::cout << a << std::endl;

  return 0;
}

