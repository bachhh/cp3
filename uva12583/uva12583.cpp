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
  char a[10000];
  int tc; cin >> tc;
  for(int cn = 1; cn <= tc; ++cn ){
    int n; cin>> n;
    int k; cin >> k;

    int t = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      for (int j = i-1; j >= max(0, i-k) ; --j) {
        if(a[j] == a[i]){
          t++;
          break;
        }
      }
    }

    printf("Case %d: %d\n", cn, t);

  }


  return 0;
}

