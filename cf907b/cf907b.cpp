#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  char matrix[9][9];

  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; j++) {
      matrix[i][j] = getchar();
      if( j < 8 && j%3 == 2 ) getchar();
    }
    getchar();
    if( i < 8 && i%3 == 2 ) getchar();
  }

  int x = getchar() - '1';
  getchar();
  int y = getchar() - '1';

  int _x = x % 3;
  int _y = y % 3;


  bool isFull = true;
  for (int i = 0; isFull && i < 3; ++i) {
    for (int j = 0; isFull && j < 3; j++) {
      if (matrix[i+3*_x][j+3*_y] == '.'){
        isFull = false;
      }
    }
  }

  if (isFull){
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; j++) {
        if (matrix[i][j] == '.'){
          matrix[i][j] = '!';
        }
      }
    }
  }
  else {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; j++) {
        if (matrix[i+3*_x][j+3*_y] == '.'){
          matrix[i+3*_x][j+3*_y] ='!';
        }
      }
    }
  }

  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; j++) {
      cout << matrix[i][j];
      if(j < 8 && j%3 == 2) cout << " ";
    }
    cout << endl;
    if(i < 8 && i%3 == 2) cout << endl;
  }

  return 0;
}

