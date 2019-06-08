#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

typedef long int int32; typedef long long int int64;
typedef unsigned long int uint32; typedef unsigned long long int uint64;
typedef pair<int, int> ii; typedef vector<ii> vii; typedef vector<int> vi;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef vector<vi> vvi;

#define PI 3.1415926535897932384626433832795
#define VISITED 1
#define UNVISITED -1
#define EXPLORED 2
#define FLOAT_EPSILON 1e-6

#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )
#define DEBUG(x) cerr << #x << " is " << x << endl;


void swap(int* a, int* b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

#define LIMIT 201

vector<iii> jiggly;
bool isSafe(int x, int y){
  int a, b, d;
  for(iii triplet : jiggly){
    a = get<0>(triplet);
    b = get<1>(triplet);
    d = get<2>(triplet);
    if ( abs(x-a)*abs(x-a) +  abs(y-b)*abs(y-b) <= d*d ){
      return false;
    }
  }
  return true;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int row, col;
  bool grid[LIMIT][LIMIT];
  queue<iii> q;

  while(cin >> row >> col && row != 0 && col != 0){
    jiggly.clear();

    while(!q.empty()) q.pop();

    for (int i = 1; i <= row; ++i) {
      for (int j = 1; j <= col; ++j) {
        grid[i][j] = true;
      }
    }
    int m;
    cin >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
      cin >> a>> b;
      grid[a][b] = false;
    }
    int n;
    cin >> n;
    int d;
    for(int i = 0; i < n; ++i){
      cin >> a >> b >> d;
      jiggly.push_back(iii {a, b, d});
    }
    q.push(iii {1, 1, 0 });
    iii t;
    int x, y;

    while(!q.empty()){
      t = q.front(); q.pop();
      x = get<0>(t);
      y = get<1>(t);
      d = get<2>(t);
      if(x == row && y == col) break;
      grid[x][y] = false;
      if (x> 0 && grid[x-1][y] && isSafe(x-1, y)){
        grid[x-1][y] = false;
        q.push(iii{x-1, y, d+1});
      }
      if (x<row && grid[x+1][y] && isSafe(x+1, y)){
        grid[x+1][y] = false;
        q.push(iii {x+1, y, d+1});
      }
      if (y>0  && grid[x][y-1] && isSafe(x, y-1)){
        grid[x][y-1] = false;
        q.push(iii {x, y-1, d+1});
      }
      if (y<col && grid[x][y+1] && isSafe(x, y+1)){
        grid[x][y+1] = false;
        q.push(iii {x, y+1, d+1});
      }
    }
    if(x == row && y == col){
      std::cout << d << std::endl;
    }
    else{
      std::cout << "Impossible." << std::endl;
    }
  }

  return 0;
}

