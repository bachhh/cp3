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

#define LIMIT 52

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// I'm just being lazy
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);

  int row, col;
  int sx, sy, dx, dy;
  string dir;
  int matrix[4][LIMIT][LIMIT];
  map<string, int> dirtoi;
  dirtoi["north"] = 0;
  dirtoi["west"] = 1;
  dirtoi["south"] = 2;
  dirtoi["east"] = 3;

  while(cin >>  row >> col && (row||col)){
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        for (int d = 0; d < 4; ++d) {
          matrix[d][i][j] = 0;
        }
      }
    }
    int a;
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        cin >> a;
        if (a==1){ for (int d = 0; d < 4; ++d) {
            matrix[d][MAX(i-1, 0)][MAX(j-1, 0)] = -1;
            matrix[d][MAX(i-1, 0)][MIN(j, col-2)] = -1;
            matrix[d][MIN(i, row-2)][MAX(j-1, 0)] = -1;
            matrix[d][MIN(i, row-2)][MIN(j, col-2)] = -1;
        } }
      }
    }

    cin >> sx >>  sy >>  dx >>  dy >> dir;
    sx--; sy--; dx--; dy--;
    queue< tuple<int, int, int, int> > q;
    q.push(iiii {sx, sy, dirtoi[dir], 0});
    matrix[dirtoi[dir]][sx][sy] = 1;
    iiii state;
    int x, y, d, currentDir;

    while(!q.empty()){
      state = q.front(); q.pop();
      x = get<0>(state);
      y = get<1>(state);
      currentDir = get<2>(state);
      d = get<3>(state);

      if (x == dx && y == dy){
        break;
      }

      // Push 3 GOs
      for (int go = 1; go <= 3; ++go) {
        int nextx = x+(-(1-currentDir)%2)*go;
        int nexty = y+((currentDir-2)%2)*go;
        if(nextx < 0 || nextx >= row-1 || nexty < 0 || nexty >= col-1 || matrix[currentDir][nextx][nexty] == -1 ){
          break;
        }
        else if(matrix[currentDir][nextx][nexty] == 0) {
          q.push(iiii {nextx, nexty, currentDir, d+1});
          matrix[currentDir][nextx][nexty] = 1;

        }
      }

      // Push 2 TURNs
      int ccw = MIN(unsigned(currentDir-1), unsigned(currentDir+3))%4;
      int cw = (currentDir+1)%4;
      if( matrix[ccw][x][y] == 0){
        q.push(iiii{x, y, ccw, d+1});
        matrix[ccw][x][y] = 1;
      }
      if( matrix[cw][x][y] == 0){
        q.push(iiii{x, y, cw, d+1});
        matrix[cw][x][y] = 1;
      }

    }

    if (x == dx && y == dy){
      printf("%d\n", d);
    }
    else printf("-1\n");
  }

  return 0;
}
