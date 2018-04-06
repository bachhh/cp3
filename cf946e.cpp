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
  int counter[10];
  while(tc--){

    memset(counter, 0, sizeof(counter[0])*10);
    int n; cin >> n;
    string s = to_string(n);
    for(char c:s){
      counter[c-'0']++;
    }
    int i = -1;
    int t = 0;
    while(i<10){
      i++;
      if(counter[i]%2 == 1){
        t++;
      }
    }
    if(s.size()%2 ==0){
    }
    else {
    }
  }
  return 0;
}

