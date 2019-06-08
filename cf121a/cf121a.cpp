#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef long long ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }


vector<ll> ln;
void gen(){
  ll n = 4;
  ln.push_back(n);
  while(n < 1000000001){
    int t = 0;
    while((n%10)==7){ t++; n /= 10; }
    n += (n==0) + 3;
    while(t--) {n*= 10; n += 4;}
    ln.push_back(n);
    //std::cout << n << std::endl;
  }
}
ll next(ll n){
  return *lower_bound(ln.begin(), ln.end(), n);
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  ln.clear();
  gen();

  ll l, r;
  cin >> l >> r;
  ll cur = next(l);

  ll o = 0;

  int li = lower_bound(ln.begin(), ln.end(), l) - ln.begin();
  while(l <= r ){
    o += ln[li]*(min(r-l+1, ln[li]-l+1));
    l = ln[li]+1;
    li++;
  }


  std::cout << o << std::endl;

  return 0;
}

