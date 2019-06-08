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

  string s, t;
  cin >> s >> t;
  int i;

  for(i = s.size()-1; i >= t.size()-1; --i){
    bool match = true;

    for(int j = 0; j < t.size() ; ++j){
      if(s[i-j] != '?' && s[i-j] != t[t.size()-1-j]) {
        match = false;
        break;
      }
    }

    if(match){
      for(int j = 0; j < t.size(); ++j){
        s[i-j] = t[t.size()-1-j];
      }
      for (int i = 0; i < s.size(); ++i) {
        if(s[i] == '?') s[i] = 'a';
      }
      std::cout << s << std::endl;
      return 0;
    }
  }
  std::cout << "UNRESTORABLE" << std::endl;

  return 0;
}

