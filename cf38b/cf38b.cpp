#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

int dx[8] ={+1, -1, +1, -1, +2, +2, -2, -2};
int dy[8] ={+2, +2, -2, -2, +1, -1, +1, -1};

bool knightAttack(int x1, int  y1,int  x2,int  y2){

  if (x1 == x2 && y1 == y2) return true;
  // x+1|y+2, x-1|y+2, x+1|y-2, x-1|y-2
  for (int i = 0; i < 8; i++) {
    if (x1 == x2+dx[i] &&
        y1 == y2+dy[i]){
      return true;
    }
  }
  return false;
}

bool rookAttack(int x1,int y1,int x2,int y2 ){
  return (x1 == x2 && y1 == y2) || (x1 == x2 || y1 == y2);
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string rook, knight;
  cin >> rook >> knight;

  int rx = rook[0] - 'a';
  int ry = rook[1] - '1';
  int kx = knight[0] - 'a';
  int ky = knight[1] - '1';
  int counter = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (!rookAttack(i, j, rx, ry) &&
          !knightAttack(i, j, rx, ry) &&
          !knightAttack(i, j, kx, ky)){
        counter++;
      }
    }
  }
  std::cout << counter << std::endl;

  return 0;
}

