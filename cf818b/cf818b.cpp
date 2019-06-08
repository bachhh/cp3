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

int mod(int a, int m){
}
//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  int l[1000];

  for (int i = 0; i < m; ++i) {
    cin >> l[i];
    l[i]--;
  }

  int v[10000] ={0};
  bitset<101> bs; bs.reset();
  for (int i = 0; i < m-1; ++i) {
    int a = (l[i+1]-l[i]+n)%n;
    if(a==0) a = n;
    if(bs[a]){
      std::cout << -1 << std::endl;
      return 0;
    }
    v[l[i]] = a;
    bs[a] = 1;
  }
  for (int i = 0; i < n; ++i) {
    cout << v[i] << " \n"[i==n-1];
  }


  return 0;
}

