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
  while(tc--){
    int p; cin >> p;
    int v[20];
    int major =0;
    int power[20] = {0};
    for (int i = 0; i < p; ++i) {
      cin >> v[i];
      major+=v[i];
    }
    major = (major)/2;
    for(int bin = 1; bin < (1<<p); ++bin){
      //std::cout << bin << std::endl;

      int colsum =0;
      for(int bit = 0; bit < p; ++bit){
        if(bin & (1<<bit)) colsum += v[bit];
      }

      for(int bit = 0;colsum <= major && bit < p; ++bit){
        if(!(bin&(1<<bit))){
          if(v[bit] + colsum > major){
            power[bit]++;
          }
        }
      }
      //if(bin == 1){cout << power[0] << endl;}

    }

    for(int i = 0;i < p; i++){
      printf("party %d has power index %d\n",i+1, power[i]);
    }
    printf("\n");
  }
  return 0;
}

