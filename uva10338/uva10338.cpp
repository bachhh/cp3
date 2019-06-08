#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef long long ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);

  cin.tie(NULL);
  int n;cin >> n;
  unsigned long long  v[21];
  v[0] =1;
  for (int i = 1; i <= 20 ; ++i) {
    v[i] = i*v[i-1];
  }
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    unsigned long long ull = v[s.size()];
    int alphabet[26] = {0};
    for(char c : s){
      alphabet[c-'A']++;
    }
    for(int i : alphabet){
      if(i>1) ull /= v[i];
    }
    printf("Data set %d: %lld\n",i, ull);
  }

  return 0;
}

