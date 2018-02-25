#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

char m[50][50];
int len[50][50];

int h, w;
int score = 0;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};


//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> h >> w;
  memset(len, 0, 50*50*sizeof(len[0][0]));

  int white = 0;

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> m[i][j];
      if (m[i][j] == '.') white++;
    }
  }

  queue<pair<int, int>> qu;
  if (m[0][0] == '.') {
    qu.push(ii(0, 0));
    len[0][0] = 1;
  }
  while(!qu.empty()){
    ii p = qu.front();
    qu.pop();
    int x = p.first;
    int y = p.second;
    m[x][y] = '#';
    for (int i = 0; i < 4; ++i) {
      int nx = x+dx[i];
      int ny = y+dy[i];
      if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
      if (m[nx][ny] != '.') continue;
      if (len[nx][ny] != 0) continue;
      len[nx][ny] = len[x][y] + 1;
      qu.push(ii(nx, ny));
    }
    //printf("%d %d\n", x, y);
  }

  int a = len[h-1][w-1];

  if( a == 0){
    std::cout << -1 << std::endl;
  }
  else{
    std::cout << white - a << std::endl;
  }

  return 0;

}

