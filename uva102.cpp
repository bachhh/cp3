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

  int a[9];
  while(cin >> a[0]){
    for (int i = 1; i < 9; ++i) { cin >> a[i]; }

    int p[3] = {0, 1, 2};
    string bestp  = "123";
    string code = "BGC";
    int mint = INT_MAX;

    do{
      int t = 0;
      for (int bin = 0; bin < 3; ++bin) {
        for (int c = 0; c < 3; ++c) {
          if(p[bin] != c) t += a[bin*3+c];
        }
      }

      if(t< mint){
        mint = t;
        for (int i = 0; i < 3; ++i) { bestp[i] = code[p[i]]; }
      }
      else if(t == mint){
        string w = "123";
        for (int i = 0; i < 3; ++i) {
          w[i] = code[p[i]];
        }
        if(w<bestp) bestp = w;
      }
    }while(next_permutation(p, p+3));

    std::cout << bestp << " " << mint << std::endl;
  }

  return 0;
}

