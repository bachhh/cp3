#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

int n, z, w;
int a[2000];
ll X(int x, int y, int i);
ll Y(int x, int y, int i);

ll X(int x, int y, int i){
  ll ma = INT64_MIN;
  if(i == n){
    return abs( x-y );
  }
  int k = i;
  while(k<n){
    ma = max<ll>(ma, Y(a[k], y, k+1));
    k++;
  }
  return ma;
}

ll Y(int x, int y, int i){
  ll mi = INT64_MAX;
  if(i == n){
    return abs( x-y );
  }
  int k = i;
  while(k<n){
    mi = min<ll>(mi, Y(x, a[k], k+1));
    k++;
  }
  return mi;
}
//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> z >> w;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  std::cout << X(z, w, 0) << std::endl;

  return 0;
}

