#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;


  static bool matrix[2001][2001];
  memset(matrix, false, sizeof(matrix[0][0])*2001*2001);

  int x, y;
  while(k--){
    cin >> x >> y;
    if (matrix[x][y] == false){
      printf("%d %d\n",x , y);
      matrix[x][y] = true;
    }
    else {
      bool found = false;
      for (int d = 1; !found && d < 2000; ++d) {

        for(int dx = -d; !found && dx <= d; ++dx){
          int dy = abs(dx)-d;
          int nx = x+dx,  ny = y+dy;

          if ( nx > 0 && ny > 0 &&
               nx <= n && ny <=m &&
               !matrix[nx][ny]){
            found = true;
            matrix[nx][ny] = true;
            printf("%d %d\n", nx, ny);
          }

          dy = d-abs(dx);
          nx = x+dx, ny = y+dy;
          if ( !found  && nx > 0 && ny > 0 &&
               nx <= n && ny <=m &&
               !matrix[nx][ny]){
            found = true;
            matrix[nx][ny] = true;
            printf("%d %d\n", nx, ny);
          }
        }
      }
    }
  }

  return 0;
}

