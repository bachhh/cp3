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
  ::cout << (int)floor(sqrt(n))*(int)floor(sqrt(n))<< std::endl;

  return 0;
}

