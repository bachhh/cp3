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

bool check(int n, int d){
  int m = pow(10, d/2);
  return ((n/m) + (n%m))* ((n/m) + (n%m))== n;
}
void printPad(int n, int p){
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  vector<vector<int>> v(9, vector<int>());

  for (int i = 2; i < 9; i+= 2) {
    int from = pow(10, i-2);
    int to = pow(10, i);
    for (int j = from; j < to; ++j) {
      if(check(j, i)) v[i].push_back(j);
    }
  }
  int n;
  while(cin >> n){
    for(int i : v[n]){
      printf ("%0*d\n", n, i);
    }
  }


  return 0;
}

