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

#define LIMIT 1001

int r,c;
char maze[LIMIT][LIMIT];

bool isMovable(int fx, int fy, int x, int y){
  if ( x < 0 || x >= r || y < 0 || y >= c) return false;
  else if ( maze[x][y] == '.' || ( maze[fx][fy] == 'F' && maze[x][y] == 'J')) return true;
  else return false;
}

bool isEscape(int x, int y){
  if ( x == 0 || x == r-1 || y == 0 || y == c-1 ) return true;
  else return false;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);
  int tc; cin >> tc;
  int jx, jy;
  queue<iii> q;
  vector<ii> f;
  while(tc--){
    std::cin >> r >> c;
    f.clear();
    while(!q.empty()) q.pop();
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        std::cin >> maze[i][j];
        if(maze[i][j] == 'J'){jx = i; jy = j;}
        if(maze[i][j] == 'F'){f.push_back(ii {i, j});}
      }
    }
    // Joe moves first
    iii t;
    int x, y, d;
    q.push(iii {jx,jy, 0});
    for(ii p : f) q.push(iii{p.first, p.second, -1});
    while(!q.empty()){
      t = q.front(); q.pop();
      x = get<0>(t); y = get<1>(t); d = get<2>(t);
      // If we pop a square adjacent the wall
      if(isEscape(x, y) && maze[x][y] == 'J' ) {
        break;
      }
      if ( isMovable(x, y, x-1, y) ){
        if(maze[x][y]=='J') {
          q.push(iii {x-1, y, d+1});
        }
        else{
          q.push(iii {x-1, y, -1});
        }
        maze[x-1][y] = maze[x][y];
      }
      if ( isMovable(x, y, x+1, y)){
        if(maze[x][y]=='J') {
          q.push(iii {x+1, y, d+1});
        }
        else{
          q.push(iii {x+1, y, -1});
        }
        maze[x+1][y] = maze[x][y];
      }
      if ( isMovable(x, y, x, y-1)){
        if(maze[x][y] == 'J') {
          q.push(iii {x, y-1, d+1});
        }
        else{
          q.push(iii {x, y-1, -1});
        }
        maze[x][y-1] = maze[x][y];
      }
      if ( isMovable(x, y, x, y+1) ){
        if(maze[x][y]=='J') {
          q.push(iii {x, y+1, d+1});
        }
        else{
          q.push(iii {x, y+1, -1});
        }
        maze[x][y+1] = maze[x][y];
      }
    }
    if (isEscape(x, y) && maze[x][y] == 'J'){
      std::cout << d+1 << std::endl;
    }
    else {
      std::cout << "IMPOSSIBLE" << std::endl;
    }
  }

  return 0;
}

