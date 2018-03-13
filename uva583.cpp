#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
#define MOD 1000000007ll
#define INF 1e9
typedef long long ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

void trim(string &s){
  while(s.back() == ' ' || s.back() == 'x') s.pop_back();
}
//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  bitset<1000001> bs;
  bs.set();
  for(int i = 2; i <= 1000; ++i){
    if(bs[i]){
      for(int j = i*i; j <= 1000001; j += i){
        bs[j] = 0;
      }
    }
  }
  vector<int> primes;
  for (int i = 2; i <= 1000000; ++i) { if(bs[i]) primes.push_back(i); }

  while(cin >> n && n){
    string s = "";
    bool neg = n<0;
    s +=  to_string(n) + " = ";
    if(neg) {
      n = -n;
      s += "-1 x ";
    }
    int i = 0;
    int p;
    while(i < primes.size()){
      p = primes[i];
      if(p*p > n) break;
      if(n%p == 0 ){
        while(n%p == 0){
          s += to_string(p) + " x ";
          n /= p;
        }
      }
      i++;
    }
    if(n>1) s += to_string(n);
    trim(s);
    std::cout << s << std::endl;
  }

  return 0;
}

