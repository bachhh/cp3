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
  int n, m; cin >> n >> m;
  char maze[50][50];

  int x, y;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> maze[i][j];
      if(maze[i][j] == 'S') {
        x = i; y= j;
      }
    }
  }

  string w; cin >> w;
  int de[4] = {0, 1, 2, 3};
  int t = 0;
  do{

    int cx = x, cy = y;
    bool flag = false;
    for(char c : w){
      int i = c -'0';
      cx += dx[de[i]];
      cy += dy[de[i]];
      if(cx < 0 || cy < 0 || cx >= n || cy >= m || maze[cx][cy] == '#'){ break; }
      if(maze[cx][cy] == 'E') {
        flag = true;
        break;
      }
    }
    if(flag) {
      t++;
    }

  }while(next_permutation(de, de+4));

  std::cout << t << std::endl;


  return 0;
}

