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


bool check(ll a){
  string w = to_string(a);
  int counter[10] = {0};
  for (char c : w) { counter[c-'0']++; }
  for (int i = 0; i < 10; ++i) { if(counter[i] >1 ) return false; }
  return true;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int tc; cin >> tc;
  while(tc--){
    ll n; cin >> n;
    int maxdigit = 10-(log10(n))+1;
    for (ll i = 1; i < pow(10, maxdigit); ++i) {
      if(check(i) && check(i*n)){
        printf("%lld / %lld = %lld\n", i*n, i, n);
      }
    }
    if(tc > 0) printf("\n");
  }


  return 0;
}

