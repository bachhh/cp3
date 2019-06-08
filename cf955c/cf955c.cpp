#include <bits/stdc++.h>

using namespace std;

#define LIMIT 1000000000000000000
#define PLIMIT 10000010
#define MOD 1000000007ll
#define INF 1e9
typedef long long ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};

ll binary(ll n){
  ll l =0, h = LIMIT, m;
  while(l<h){
    m = l+(h-l)/2;
    if(m*m <= n){
      l = m;
    }
    else {
      h = m-1;
    }
  }
  return l;
}
//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  vector<ll> v;

  for(int p = 3; p <= 18; ++p){
    int j =2;
    ll pj = pow(j, p);
    while(pj <  LIMIT){
      v.push_back(pj);
      j++;
      pj = pow(j, p);
    }
  }
  std::cout << v.size() << std::endl;
  sort(v.begin(), v.end());
  int q; cin >> q;
  while(q--){
    ll l, r;

  }
  return 0;
}

