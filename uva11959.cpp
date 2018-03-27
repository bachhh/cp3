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

string rotate(int axis, int s, string a){
  string acp = a;
  if(axis == 0){
    int v[4] = {0,1,5,3};
    for (int i = 0; i < 4; ++i) {
      acp[v[i]] = a[v[( i+s ) % 4]];
    }
  }
  if(axis==1){
    int v[4] = {1,4,3,2};
    for (int i = 0; i < 4; ++i) {
      acp[v[i]] = a[v[( i+s ) %4]];
    }
  }
  if(axis==2){
    int v[4] = {0,4,5,2};
    for (int i = 0; i < 4; ++i) {
      acp[v[i]] = a[v[( i+s )%4]];
    }
  }
  return acp;
}
bool check(string d1, string d2){
  string w;
  for (int a = 0; a < 3; ++a) {
    for (int b = 0; b < 4; ++b) {
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
          for (int l = 0; l < 3; ++l) {
            for (int m = 0; m < 4; ++m) {
              w = rotate(a, b, d2);
              w = rotate(i, j, w);
              w = rotate(l, m, w);
              std::cout << w << std::endl;
              if(d1==w) return true;
            }
          }
        }
      }
    }
  }
  return false;
}
//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int tc; cin >> tc;
  string ans[2] = {"Not Equal", "Equal"};
  while(tc--){
    string d1, d2;
    cin >> d1 >> d2;
    std::cout << ans[check(d1, d2)] << std::endl;
  }


  return 0;
}

