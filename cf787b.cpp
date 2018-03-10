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
  int n, m;

  cin >> n >> m;

  int counter[10001];

  for (int i = 0; i < m; ++i) {
    memset(counter, 0, sizeof(counter[0])*10001);
    int k; cin >> k;
    int flag = true;
    for (int j = 0; j < k; ++j) {
      int a; cin >> a;
      if(counter[abs(a)] != a) counter[abs(a)] += a;
      if(counter[abs(a)] == 0){ flag = false; }
    }

    if(flag){
      std::cout << "YES" << std::endl;
      return 0;
    }

  }
  std::cout << "NO" << std::endl;

  return 0;
}

