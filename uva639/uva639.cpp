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

bool checkrow(char m[4][4], int config, int n){
  for(int row = 0;row<n; ++row){
    int lastrook = -8;
    for(int col =0;col<n; ++col){
      int bit = (row*4 + col);
      if (config&(1<<bit)){
        // rookies placed inside a wall
        if(m[row][col]== 'X'){
          return false;
        }
        // rookies next to eachother
        else if(col == lastrook+1) {
          return false;
        }
        // if there a wall inbetween
        else if(col == lastrook+2){
          if (m[row][lastrook+1] != 'X') return false;
        }
        else if(col == lastrook+3){
          if(m[row][lastrook+1] != 'X' && m[row][lastrook+2] !='X') return false;
        }
        lastrook = col;
      }
    }
  }
  return true;
}

bool checkcol(char m[4][4], int config, int n){

  for(int col =0;col<n; ++col){
    int lastrook = -8;
    for(int row = 0;row<n; ++row){
      int bit = (row*4 + col);
      if (config&(1<<bit)){
        // rookies placed inside a wall
        if(m[row][col]== 'X'){
          return false;
        }
        // rookies next to eachother
        else if(row== lastrook+1) {
          return false;
        }
        // if there a wall inbetween
        else if(row== lastrook+2){
          if (m[lastrook+1][col] != 'X') return false;
        }
        else if(row== lastrook+3){
          if (m[lastrook+1][col] != 'X' && m[lastrook+2][col] != 'X') return false;
        }
        lastrook = row;
      }
    }
  }
  return true;
}
void printB(int bin, int n){
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if( bin & (1<<(i*4+j)) ) {
        cout << 1;
      }
      else cout << 0;
    }
    cout << "\n";
  }
  cout << "\n";
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while(cin >> n && n){
    char m[4][4];

    for (int i = 0; i <n ; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> m[i][j];
      }
    }

    int maxr = -1;

    for (int config = 0; config < (1<<16); ++config) {
      bool legal = checkrow(m, config, n) && checkcol(m, config, n);
      if(legal){
        int r= 0;
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
            if(config&(1<<(4*i+j))) r++;
          }
        }
        if(r>maxr){ maxr = r; }
      }
    }

    std::cout << maxr << std::endl;

  }

  return 0;
}

