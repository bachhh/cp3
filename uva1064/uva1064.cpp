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

template <typename T> void PrintBit(T a, int n){
  for (int i = n-1; i >= 0 ; --i) {
    if(a &(1<<i)) cout <<"1";
    else cout << "0";
  }
  cout << endl;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int tc; cin >> tc;
  while(tc--){
    int p; cin >> p;
    int n; cin >> n;

    vector<short> v; v.clear();
    for (int i = 0; i < n; ++i) {
      short t = 0;
      short bit = 0;
      for (int j = 0; j < p ; ++j) {
        cin >> bit;
        t <<= 1;
        t |= bit;
      }
      v.push_back(t);
    }

    int mint = INT_MAX;
    for (short bin = 0; bin < (1<<p); ++bin) {
      set<short> s; s.clear();
      for(short i : v){
        s.insert(i&bin);
      }
      if(s.size()==n){
        int t = 0;
        for (int j = 0; j < p; ++j) {
          if(bin&(1<<j)) t++;
        }
        //std::cout << t << std::endl;
        mint = min(t, mint);
      }
    }

    std::cout << mint << std::endl;
  }

  return 0;
}

