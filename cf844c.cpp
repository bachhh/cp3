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
  int v1[100000];
  int v2[100000];

  for (int i = 0; i < n; ++i) {
    cin >> v1[i];
    v2[i] = v1[i];
  }
  sort(v1, v1+n);
  int sub1[100000];
  int sub2[100000];
  int j = 0;
  int k = 0;

  for (int i = 0; i < n; ++i) {
    if(v1[i] != v2[i]){
      sub1[j++] = i+1;
    }
    else {
      sub2[k++] = i+1;
    }
  }

  std::cout << ((j>0)+k) << std::endl;
  if(j){
    std::cout << j << " ";
    for (int i = 0; i < j; ++i) {
      cout << sub1[i] << " \n"[i==j-1];
    }
  }
  if(k){
    for (int i = 0; i < k; ++i) {
      cout << 1 << " "<< sub2[i] << endl;
    }
  }

  return 0;
}

