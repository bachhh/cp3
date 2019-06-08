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

  int tc; cin >> tc;
  while(tc--){
    int n; cin >> n;

    bool flag = false;

    for (int i = 0;!flag && i*i*3 <=n ; ++i) {
      for (int j = i; !flag && j*j+i*i*2 <=n ; ++j) {
        for (int k = j; !flag && k*k + i*i + j*j <=n ; ++k) {
          if(i*i + j*j + k*k == n){
            flag = true;
            printf("%d %d %d\n",i, j, k);
          }
        }
      }
    }

    if(!flag) std::cout << -1 << std::endl;
  }


  return 0;
}

