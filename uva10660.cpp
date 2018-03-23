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

typedef struct area{
  int x, y, p;
  area(int _x, int _y, int _p) : x(_x) , y(_y), p(_p){}
}Area;

bool nextString(int* s){
}
//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int tc; cin >> tc;
  while(tc--){

    vector<Area> m; m.clear();
    int n;cin>> n;
    int x, y, p;

    int v[25] ={0};

    for (int i = 0; i < n; ++i) {
      cin >>x >> y >>p;
      m.push_back(Area(x-1, y-1, p));
    }

    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 5; ++j) {
        int t = 0;
        for (int k = 0; k < n; ++k) {
          t += (abs(m[k].x - i) + abs(m[k].y-j))*m[k].p;
        }
        v[(i)*5+ j] = t;
        //std::cout << v[5*i+j] << std::endl;
      }
    }


    int s[5] = {0, 1, 2, 3, 4};
    do {

    }while(nextString(s));

  }


  return 0;
}

