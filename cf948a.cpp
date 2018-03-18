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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int r, c;
  cin >> r >> c;
  char m[500][500];
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> m[i][j];
    }
  }

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if(m[i][j] == 'S'){

        for (int k = 0; k < 4; ++k) {
          int ni = i+dx[k];
          int nj = j+dy[k];
          if(ni < 0 || nj < 0 || ni >= r || nj >= c) continue;
          if(m[ni][nj] == 'W'){
            std::cout << "No" << std::endl;
            return 0;
          }
          if(m[ni][nj] == '.') m[ni][nj] = 'D';
        }
      }
    }
  }
  std::cout << "Yes" << std::endl;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      std::cout << m[i][j];
    }
    std::cout << std::endl;
  }

  return 0;
}

