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

int LSS(string a, string b){
  int i = 0, j = 0, maxt = 0, as = a.size(), bs = b.size();
  for (int i = 0; i < as; ++i) {
    for (int j = 0; j < bs; ++j) {
      int t =0;
      for (int k = 0; k+i<as && k+j<bs; ++k) {
        if(a[i+k] == b[j+k]){
          t++;
        }
      }
      maxt = max(maxt, t);
    }
  }
  return maxt;
}
//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);


  int tc; cin >> tc;
  while(tc--){
    int n; cin >> n;
    int t =0;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) { cin >> v[i]; }

    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        t = max(t, LSS(v[i], v[j]));
      }
    }

    std::cout << t << std::endl;
  }

  return 0;
}

