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
  string s; cin >> s;
  int t =0;
  for(char c : s){
    if (c=='a' || c == 'i' || c == 'u' || c == 'e' || c == 'o'){
      t++;
    }
    else if(c == '1' || c== '3' || c== '5' || c== '7' || c=='9' ){
      t++;
    }
  }
  std::cout << t << std::endl;

  return 0;
}

