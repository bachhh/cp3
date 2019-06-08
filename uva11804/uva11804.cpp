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

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tc; cin >> tc;
  for(int cn = 1; cn <= tc; ++cn ){
    map<int, string> m;
    vector<ii> v;
    string s; int a, d;
    for (int i = 0; i < 10; ++i) {
      cin >> s >> a >> d;
      m[i] = s;
      v.push_back(ii(a, d));
    }

    int maxa=0, maxd=0;
    vector<string> vv;
    for (int i = 0; i < 10; ++i) {
      for (int j = i+1; j < 10; ++j) {
        for (int k = k; k < 10; ++k) {
          for (int l= 0;l  < 10; ++l) {
            for (int n = 0;n  < 10; ++n) {
              int attack = v[i].first + v[j].first +
                           v[k].first + v[l].first +
                           v[n].first;

              int defense= v[i].second + v[j].second +
                           v[k].second + v[l].second +
                           v[n].second;
              if(attack== maxa&&defense > maxd){
                maxa = attack;
                maxd = defense;
                vv = {m[i],m[j],m[k],m[l],m[n]};
              }
              if (attack>maxa){
                maxa = attack;
                maxd = defense;
                vv = {m[i],m[j],m[k],m[l],m[n]};
              }
            }
          }
        }
      }
    }
    printf("Case %d:\nn", cn);
    sort(vv.begin(), vv.end());
    for(str)
  }


  return 0;
}

