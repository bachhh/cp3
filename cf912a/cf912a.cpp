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
  ll a, b, x, y, z;
  cin >> a >> b >> x >> y >> z;

  ll t = 0;

  if(x*2 > a){
    t+= x*2-a;
    if(z*3> b){
      t += z*3 - b;
      t += 2*y;
    }
    else{
      b -= z*3;
      t+= y;
      if(b<y) t+= y-b;
    }
  }
  else{
    a-= x*2;
    if(z*3> b){
      t+= z*3-b;
      t+= y;
      if(a<y) t+=y-a;
    }
    else{
      b-= z*3;
      if(b<y) t+=y-b;
      if(a<y) t+=y-a;
    }
  }
  std::cout << t << std::endl;

  return 0;
}

