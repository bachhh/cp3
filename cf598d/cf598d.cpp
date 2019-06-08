#include <bits/stdc++.h>

using namespace std;

#define LIMIT 1000
#define VISITED 1
#define UNVISITED -1

void debug(pair<int, int> p){
  std::cout << p.first+1 << " | " << p.second+1 << std::endl;
}

int n, m, k;
char matrix[LIMIT][LIMIT];
int isVisited[LIMIT][LIMIT];
int dp[LIMIT][LIMIT];
pair<int, int> parent[LIMIT][LIMIT];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int paintCount(int x, int y){
  int output = 0;
  if (x == 0 || x == n-1 ) output += 1;
  if (y == 0 || y == m-1 ) output += 1;
  if (x > 0   && matrix[x-1][y] == '*') output += 1;
  if (y > 0   && matrix[x][y-1] == '*') output += 1;
  if (x < n-1 && matrix[x+1][y] == '*') output += 1;
  if (y < m-1 && matrix[x][y+1] == '*') output += 1;
  return output;
}

void dfs_dp(int x, int y, int value){
  if (x < 0 || x >= n || y < 0 || y >= m) return;
  if (matrix[x][y] == '*') return;
  if (dp[x][y] != -1) return;
  dp[x][y] = value;
  for (int i = 0; i < 4; i++) {
    int nx = x+dx[i], ny = y+dy[i];
    if (nx < 0 || nx >= n || ny<0 || ny >= m) continue;
    if (matrix[nx][ny] == '*') continue;
    dfs_dp(nx, ny, value);
  }
}

int dfs(int x, int y){
  if (x < 0 || x >= n || y < 0 || y >= m) return 0;
  if (matrix[x][y] == '*') return 0;

  if (isVisited[x][y] == VISITED) return 0;
  isVisited[x][y] = VISITED;

  int output = paintCount(x, y);
  for (int i = 0; i < 4; i++) {
    int nx = x+dx[i], ny = y+dy[i];
    if (nx< 0 || nx >= n || ny<0 || ny >= m) continue;
    if (matrix[nx][ny] == '*') continue;
    if(isVisited[nx][ny] == VISITED) continue;

    output += dfs(nx, ny);
  }

  return output;
}


//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;
  int x, y;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> matrix[i][j];
      isVisited[i][j] = UNVISITED;
      dp[i][j] = -1;
    }
  }


  for (int i = 0; i < k; i++) {
    cin >> x >> y;
    x--;
    y--;
    if(dp[x][y] == -1){
      int output = dfs(x, y);
      dfs_dp(x, y, output);
    }
    std::cout << dp[x][y] << std::endl;
  }

  return 0;
}

