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
  int n; cin >> n;
  int a[1000003];
  int mint= INT_MAX;
  a[n+1] = 1000000;
  a[0] = 1;

  int x, y;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i <=n; ++i) {
    if(max(a[i]-a[0] ,  a[n+1] -a[i+1])< mint){
      mint = max(a[i]-a[0] , a[n+1]-a[i+1]);
      x = i;
    }
  }

  std::cout << max(a[x]-a[0] , a[n+1]- a[x+1]) << std::endl;

  return 0;
}

