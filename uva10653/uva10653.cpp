#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

typedef long int int32; typedef long long int int64;
typedef unsigned long int uint32; typedef unsigned long long int uint64;
typedef pair<int, int> ii; typedef vector<ii> vii; typedef vector<int> vi;
typedef tuple<int, int, int> iii;
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

#define LIMIT 1000

void swap(int* a, int* b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}
bool m[LIMIT][LIMIT];

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int row, col, a, b, c, d;
  int s_x, s_y, d_x, d_y;
  while(cin >> row >> col && row != 0){
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; j++) {
        m[i][j] = true;
      }
    }

    cin >> a;
    while(a--){
      cin >> b >> c;
      for (int i = 0; i < c; i++) {
        cin >> d;
        m[b][d] = false;
      }
    }

    cin >> s_x >> s_y >> d_x >> d_y;
    queue<iii> q;
    q.push(iii {s_x, s_y, 0});
    iii t;

    while(!q.empty()){
      t = q.front(); q.pop();
      int x = get<0>(t);
      int y = get<1>(t);
      int d = get<2>(t);
      m[x][y] = false;

      if(x == d_x && y == d_y){
        break;
      }

      if(x > 0 && m[x - 1][y] ){
        q.push(iii {x-1, y, d+1 });
        m[x-1][y] = false;
      }

      if(x < row-1 && m[x + 1][y]){
        q.push(iii { x+1 , y, d+1 });
        m[x+1][y] = false;
      }

      if(y > 0 && m[x][y-1]){
        q.push(iii { x , y-1, d+1 });
        m[x][y-1] = false;
      }

      if(y < col-1 && m[x][y+1]){
        q.push(iii { x, y+1, d+1 });
        m[x][y+1] = false;
      }

    }
    cout << get<2>(t) << endl;
  }

  return 0;
}

