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
  int n, m;
  cin >> n >> m;
  int x[1000000];
  int y[1000000];

  for (int i = 0; i < n; ++i) { cin >> x[i]; }
  for (int i = 0; i < m; ++i) { cin >> y[i]; }
  int i = 0, j = 0;
  int o = 0;
  while(i < n && j < m){
    if(x[i] < y[j]){
      i++;
      x[i] += x[i-1];
    }
    else if(x[i] > y[j]){
      j++;
      y[j] += y[j-1];
    }
    else {
      i++;
      j++;
      o++;
    }
  }
  std::cout << o << std::endl;

  return 0;
}

