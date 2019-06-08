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

template <typename T>
void PrintBit(T a, int n){
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
    int n, p;
    cin >> p >> n;
    vector<short> v(n);
    for (int i = 0; i < n; ++i) {
      short mask = 0;
      for (int j = 0; j < p; ++j) {
        short b;
        mask<<=1;
        cin >> b; mask |= b;
      }
      //PrintBit(mask, p);
      v[i] =mask;
    }

    set<short> s;
    int mint = INT_MAX;

    for(int bit = 0; bit< (1<<p); ++bit){
      s.clear();
      for(short i : v){
        s.insert(i&bit);
      }

      if(s.size()==n){
        int t = 0;
        for (int j = bit; j > 0; j>>=1) {
          if(j&1) t++;
        }
        mint = min(mint, t);
      }
    }
    std::cout << mint << std::endl;
  }


  return 0;
}
