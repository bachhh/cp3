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
  int n, k;
  cin >> n >> k;
  vector<vector<string>> v(101, vector<string>(0));

  string s;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    v[s.size()].push_back(s);
  }

  string w; cin >> w;
  int maxt =  0;
  int mint =  0;

  for(int i = 0; i < w.size(); ++i){
    vector<string> vs = v[i];

    maxt+= vs.size();
    mint+= vs.size();
  }

  mint += (mint/k)*5;
  mint++;
  int counter = 0;

  for(string a : v[w.size()]){
    if (a != w){ maxt++; }
  }

  maxt += (maxt/k)*5;

  maxt++;

  printf("%d %d\n",mint, maxt);

  return 0;
}

