#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  map<ll, ll> m;
  ll a;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    m[a]++;
  }
  ll o = 0;
  for(auto p : m){
    if (p.first > p.second){
      o += p.second;
    }
    else {
      o += p.second - p.first;
    }
  }

  std::cout << o << std::endl;
  return 0;
}

