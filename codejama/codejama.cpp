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
  int t; cin >> t;
  int d;
  string p;
  int s= 0, c = 0;

  for (int i = 1; i <= t; ++i) {
    cin >> d >> p;
    vector<int> v; v.clear();
    int counter =0;
    int dmg = 0;
    for(char c : p){
      if(c == 'C'){
        counter++;
      }
      else if (c=='S'){
        dmg+=(1<<counter);
        v.push_back(1<<counter);
        counter =0;
      }
    }
    v.push_back(0);
    int t = 0;
    while(dmg > d){
      int ma = -1, mi;
      for (int i = 0; i < v.size(); ++i) {
        if(v[i] > ma){
          ma = v[i];
          mi = i;
        }
      }
      dmg -= v[mi] <<1;
      v[mi]<<=1;
      dmg+= v[mi+1]>>1;
      v[mi+1]>>=1;
      t++;
    }
    printf("Case #%d: %d\n",i, t);
  }


  return 0;
}

