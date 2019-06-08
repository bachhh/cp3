#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int mind = 65;
  int a;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    int d = 0;
    while(a%2==0) {a= a>>1; d++;}
    mind = min(mind, d);
  }
  std::cout << mind << std::endl;

  return 0;
}

