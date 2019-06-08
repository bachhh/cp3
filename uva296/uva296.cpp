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

bool check (string g, string s, char p, char d){
  string ss = s;
  char t = '0';
  for (int i = 0; i < 4; ++i) {
    if(ss[i] == g[i] ){
      ss[i] = '.';
      g[i] = '*';
      t++;
    }
  }

  if (t != d) return false;
  char t2 = '0';
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if(ss[i] == g[j] && i != j) {
        ss[i] = '.';
        g[j] = '*';
        t2++;
      }
    }
  }
  return t2 ==p;
}


bool nextString(string &s){
  if(s == "9999") return false ;
  int co = 1;
  for (int i = 3; i >= 0; --i) {
    s[i]+= co;
    if(s[i] <='9') break;
    else {
      co = s[i] - '9';
      s[i] = '0' + co - 1;
    }
  }
  return true;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int tc; cin >> tc;
  string m[10][2];

  //std::cout << digit("0218", "3411") << std::endl;
  while(tc--){
    int n; cin >> n;

    string s =  "000/";

    for (int i = 0; i < n; ++i) { cin >> m[i][0] >> m[i][1]; }
    int t = 0;

    string ret[3] = {"impossible", "", "indeterminate"};

    while(t < 2 && nextString(s)){
      bool flag = true;
      for (int i = 0; t < 2 && i < n; ++i) {
        flag &= check(m[i][0], s ,m[i][1][2], m[i][1][0]);
      }
      if(flag){
        t++;
        ret[1] = s;
      }
    }
    std::cout << ret[t] << std::endl;
  }

  return 0;
}

