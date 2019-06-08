#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
#define UNVISITED 0
#define VISITED 1

int n, m;
int teleporter;
int counter;
int matrix[203][203] = {0};

int dx[4] = {-1, 0, 1,  0};
int dy[4] = { 0, 1, 0, -1};
vector<pair<int, int>> route;

bool dfs(int x, int y){
  if (x < 1 || x > n || y < 1 || y > m) return false;
  // If we return to the origin after visited every node
  if(teleporter == 0 && x == 1 && y == 1 && counter == m*n){
    printf("%d %d\n", x, y);
    return true;
  }
  else if(teleporter == 1 && x == n && y == m && counter == m*n-1){
    printf("%d %d\n", x, y);
    return true;
  }
  else if (matrix[x][y] == VISITED){
    return false;
  }
  counter++;
  matrix[x][y] = VISITED;
  for (int i = 0; i < 4; i++) {
    if(dfs(x+dx[i], y+dy[i]) == true){
      printf("%d %d\n", x, y);
      return true;
    }
  }
  counter--;
  matrix[x][y] = UNVISITED;
  return false;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  if(n + m == 3){
    printf("0\n");
    teleporter = 0;
  }
  else if(  (n== 1 || m == 1) || (n%2 && m%2) ){
    printf("1\n");
    printf("1 1 %d %d\n", n, m);
    printf("1 1 \n");
    teleporter = 1;
  }
  else {
    printf("0\n");
    teleporter = 0;
  }
  counter = 0;
  dfs(1, 1);

  return 0;
}

