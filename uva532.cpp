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

#define LIMIT 100

void swap(int* a, int* b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int row, col, level;
  int a, b, c, d;
  int s_x, s_y, d_x, d_y;

  char dungeon[LIMIT][LIMIT][LIMIT];

  queue<iiii> q;

  while(cin >> level >> row >> col   && (row != 0 || col != 0 || level != 0) ){

    while(!q.empty()) q.pop();

    int s_r, s_c, s_l;
    int d_r, d_c, d_l;

    for (int i = 0; i < level; i++) {
      for (int j = 0; j < row; j++) {
        for (int k = 0; k < col; k++) {
          cin >> dungeon[i][j][k];
          if (dungeon[i][j][k] == 'S'){
            s_l = i; s_r = j; s_c = k;
          }
          else if (dungeon[i][j][k] == 'E'){
            d_l = i; d_r = j; d_c = k;
          }
        }
      }
    }

    q.push(iiii {s_l, s_r, s_c, 0});
    iiii t;
    while(!q.empty()){
      t = q.front(); q.pop();

      int l = get<0>(t);
      int r = get<1>(t);
      int c = get<2>(t);
      int d = get<3>(t);

      if ( l == d_l && r == d_r && c == d_c ){
        break;
      }
      dungeon[l][r][c] = '#';
      if(l > 0 && dungeon[l-1][r][c] != '#'){
        q.push(iiii {l-1, r, c, d+1});
        dungeon[l-1][r][c] = '#';
      }
      if(l < level-1 && dungeon[l+1][r][c] != '#'){
        q.push(iiii {l+1, r, c, d+1});
        dungeon[l+1][r][c] = '#';
      }

      if(r > 0 && dungeon[l][r-1][c] != '#'){
        q.push(iiii {l, r-1, c, d+1});
        dungeon[l][r-1][c] = '#';
      }
      if(r < row-1 && dungeon[l][r+1][c] != '#'){
        q.push(iiii {l, r+1, c, d+1});
        dungeon[l][r+1][c] = '#';
      }

      if(c > 0 && dungeon[l][r][c-1] != '#'){
        q.push(iiii {l, r, c-1, d+1});
        dungeon[l][r][c-1] = '#';
      }
      if(c < col-1 && dungeon[l][r][c+1] != '#'){
        q.push(iiii {l, r, c+1, d+1});
        dungeon[l][r][c+1] = '#';
      }
    }


    if ( get<0>(t) == d_l && get<1>(t) == d_r && get<2>(t) == d_c ){
      printf("Escaped in %d minute(s).\n", get<3>(t));
    }
    else {
      printf("Trapped!\n");
    }
  }

  return 0;
}

