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
  int a[1000];
  int c = 1;
  while(cin >> n && n){

    int sum[1000010], k=0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      for (int j = i+1; j < n; ++j) {
        sum[k] = a[i]+a[j];
        k++;
      }
    }

    sort(sum, sum+k);
    sum[k] = INT_MAX;
    int m; cin >> m;

    printf("Case %d:\n", c++);
    for (int i = 0; i < m; ++i) {
      int t; cin>> t;

      int j = lower_bound(sum, sum+k, t) - sum;
      int s;
      if(j > 0  ){
        if(sum[j] - t < t - sum[j-1]){
          s = sum[j];
        }
        else {
          s = sum[j-1];
        }
      }
      else {
        s = sum[j];
      }
      printf("Closest sum to %d is %d\n", t, s);
    }
  }


  return 0;
}

