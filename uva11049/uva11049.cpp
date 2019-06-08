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

int wall[3][4];

bool moveEast(int x, int y){
  for (int i = 0; i < 3; i++) {
    if(wall[i][0] ==  wall[i][2] &&
       x == wall[i][0] &&
       y > wall[i][1] &&
       y <= wall[i][3]){
      return false;
    }
  }
  return true;
}

bool moveWest(int x, int y){
  for (int i = 0; i < 3; i++) {
    if(wall[i][0] ==  wall[i][2] &&
       x == wall[i][0]+1 &&
       y > wall[i][1] &&
       y <= wall[i][3]){
      return false;
    }
  }
  return true;
}

bool moveNorth(int x, int  y){
  for (int i = 0; i < 3; i++) {
    if(wall[i][1] ==  wall[i][3] &&
       y == wall[i][1]+1 &&
       x > wall[i][0] &&
       x <= wall[i][2]){
      return false;
    }
  }
  return true;
}

bool moveSouth(int x, int y){
  for (int i = 0; i < 3; i++) {
    if(wall[i][1] ==  wall[i][3] &&
       y == wall[i][1] &&
       x > wall[i][0] &&
       x <= wall[i][2]){
      return false;
    }
  }
  return true;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int s_r, s_c, d_r, d_c;

  queue<ii> q;
  char dir[7][7];
  while(cin >> s_r >> s_c && s_r != 0 && s_c != 0){
    cin >> d_r >> d_c;

    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 4; j++) {
        cin >> wall[i][j];
      }
    }

    for (int a = 0; a <= 6; a++) {
      for (int b = 0; b <= 6; b++) {
        dir[a][b] = '.';
      }
    }
    while(!q.empty()) q.pop();

    q.push(ii {s_r, s_c});
    dir[s_r][s_c] = '#';
    while(!q.empty()){
      int x = q.front().first;
      int y = q.front().second;
      q.pop();

      if (x == d_r && y == d_c) break;
      if (x > 1 && moveWest(x, y) && dir[x-1][y] == '.'){
        q.push(ii {x-1, y});
        dir[x-1][y] = 'E';
      }
      if (x < 6 && moveEast(x, y) && dir[x+1][y] == '.'){
        q.push(ii {x+1, y});
        dir[x+1][y] = 'W';
      }
      if (y < 6 && moveSouth(x, y) && dir[x][y+1] == '.'){
        q.push(ii {x, y+1});
        dir[x][y+1] = 'N';
      }
      if (y > 1 && moveNorth(x, y) && dir[x][y-1] == '.'){
        q.push(ii {x, y-1});
        dir[x][y-1] = 'S';
      }
    }

    int x = d_r, y = d_c;
    vector<char> output;

    while(!(x == s_r && y == s_c)){
      if (dir[x][y] == 'E'){
        output.push_back('W');
        x++;
      }
      if (dir[x][y] == 'W'){
        output.push_back('E');
        x--;
      }
      if (dir[x][y] == 'N'){
        output.push_back('S');
        y--;
      }
      if (dir[x][y] == 'S'){
        output.push_back('N');
        y++;
      }
    }

    for(int i = output.size()-1; i >= 0; --i){
      cout << output[i];
    }
    cout << endl;

  }

  return 0;
}

