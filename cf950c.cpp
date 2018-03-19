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

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s; cin >> s;
  int l = 0;
  while(l < s.size() && s[l] != '0') l++;
  if(l == s.size()){
    std::cout << -1 << std::endl;
    return 0;
  }
  int r = 0;
  while(r < s.size() && s[r] != '0') r++;
  if(r == s.size()){
    std::cout << -1 << std::endr;
    return 0;
  }


  return 0;
}

