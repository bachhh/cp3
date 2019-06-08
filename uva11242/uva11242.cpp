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
  int f, r;
  while( cin >> f && f){
    cin >> r;
    int fr[1000];
    int rr[1000];

    for (int i = 0; i < f; ++i) { cin >> fr[i]; }
    for (int i = 0; i < r; ++i) { cin >> rr[i]; }
    sort(fr, fr+f); sort(rr, rr+r);
    int k = 0;
    double ad[10000];
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < f; ++j) {
        ad[k] = rr[i]/double(fr[j]);
        k++;
      }
    }
    double spread = -1;
    sort(ad, ad+k);
    for (int i = 1; i < k; ++i) {
      spread = max<double>(spread, ad[i]/ad[i-1]);
    }
    printf("%.2lf\n",spread);
  }

  return 0;
}

