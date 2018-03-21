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
  int n;
  while(cin >> n){
    int start[24];
    int istart[25];
    int finish[24];
    for (int i = 0; i < n; ++i) {
      cin >> start[i];
      istart[start[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
      cin >> finish[i];
    }
    int t = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        if(istart[finish[j]] < istart[finish[i]]) t++;
      }
    }
    std::cout << t << std::endl;

  }

  return 0;
}

