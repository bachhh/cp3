#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

ll toInt(int v[14]){
  ll ret = 0;
  for(int i = 10;  i >= 0 ; --i){
    ret *= 10;
    ret += v[i];
  }
  return ret;
}

void toArray(int v[14], ll n){

  while(n%10 == 0) n /= 10;

  for (int i = 0; i < 14; ++i) {
    v[i] = n%10;
    n/= 10;
  }
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m;

  int d[14];

  while(cin  >> n >> m){

    memset(d, 0,sizeof(int)*14);
    d[0] = 1;
    ll temp;

    for (ll i = n; i > n-m; --i) {
      temp = toInt(d);
      ll r = i;
      while(r%10 == 0) r/= 10;
      temp *= r;
      toArray(d, temp);
      //std::cout << temp << std::endl;
    }
    int j = 0; while(d[j] == 0) j++;
    std::cout << d[j] << std::endl;
  }

  return 0;
}

