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

int toInt(string s){
  int ret = 0;
  for (auto c : s) {
    ret += c-'a'+1;
    ret <<=5;
  }
  return ret>>5;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  while(getline(cin, s)){
    if (s=="" || s == " ")break;
    int ind = 0, n = 0;
    int v[10000];
    while(ind < s.size()){
      string w =  s.substr(ind+(ind>0),s.find(' ',ind+1)-ind-(ind>0) );
      ind = s.find(' ', ind+1);
      if(w== "" || w == " ") continue;
      v[n++] = toInt(w);
    }

    ll c = 1;
    while(true){
      bool flag = true;
      for (int i = 0; flag && i < n; ++i) {
        for (int j = i+1; flag && j < n; ++j) {
          if( (c/v[i])%n == (c/v[j])%n){
            c = min((c/v[i]+1)*v[i], (c/v[j]+1)*v[j]);
            flag = false;
          }
        }
      }
      if(flag){
        std::cout << s << std::endl<< c << std::endl<< std::endl;
        break;
      }
    }

  }

  return 0;
}

