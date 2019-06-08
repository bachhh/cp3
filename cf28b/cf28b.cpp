#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef long long ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }


int am[100][100];
int n;
int isVisited[100];

bool dfs(int i, int j){
  if(i == j) return true;
  bool flag = false;
  isVisited[i] = 1;
  for (int k = 0; k < n; ++k) {
    /* std::cout << am[i][k] << ":" << isVisited[k] << std::endl; */
    if(am[i][k] == 1 && isVisited[k] == 0){
      flag |= dfs(k, j);
    }
  }
  isVisited[i] = 0;
  return flag;
}
//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  int p[100];

  memset(am, 0, sizeof(am[0][0])*100*100);
  memset(isVisited, 0, sizeof(isVisited[0])*100);

  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    p[i]--;
  }

  for (int i = 0; i < n; ++i) {
    int d; cin >> d;
    if(i+d < n){
      am[i][i+d] = 1;
      am[i+d][i] = 1;
    }
    if(i-d >= 0){
      am[i][i-d] = 1;
      am[i-d][i] = 1;
    }
  }

  for (int i = 0; i < n; ++i) {
    if(!dfs(i, p[i])) {
      std::cout << "NO" << std::endl;
      return 0;
    }
  }
  std::cout << "YES" << std::endl;

  return 0;
}

