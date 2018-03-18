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

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int m = 131071;
  int m2 = MOD;
  int memoi[10001];

  for (int i = 0; i <= 10000; ++i) {
    int y = i;
    ll r = 1, b = 2;
    while(y){
      if(y&1) r = (r*b)%m;
      y >>=1;
      b = (b*b)%m;
    }
    memoi[i] = r;

  }

  string s;
  while(cin>> s){
    string w = "";
    while(s.back() != '#'){
      cin >> w;
      s += w;
    }
    ll r = 0;

    for (int i = s.size()-2; i>= 0; --i) {
      if(s[i] == '1' ){
        r = (r+memoi[s.size()-2-i])%m;
      }
    }

    //std::cout << r << std::endl;
    //std::cout << r%m2 << std::endl;
    if(r== 0){
      std::cout << "YES" << std::endl;
    }
    else {
      std::cout << "NO" << std::endl;
    }
  }

  return 0;
}

