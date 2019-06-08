#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

int a[2][100];
int n;
int dfs(int x, int y){
  if (x< 0 || y>= n || x >1 || y < 0) return INT_MIN;
  if(x == 1 && y == n-1) return a[x][y];
  return a[x][y] + max(dfs(x+1, y), dfs(x, y+1));
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }

  std::cout << dfs(0, 0) << std::endl;

  return 0;
}

