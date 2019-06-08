#include <bits/stdc++.h>
#define EPS 1e-9

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int x, y;
  cin >> x >> y;
  //fuck geometry, i'm iterating all points
  int _x = 0, _y =0, dir = 0;

  int circle = 0;
  int turns = 0;
  while(_x != x || _y != y){
    if(_x == circle +1 && _y == -circle){
      dir = 1;
      turns++;
      circle++;
    }
    else if (abs(_x) == circle && abs(_y) == circle &&
        !(_x == circle && _y==-circle)){
      dir++;
      dir%=4;
      turns++;
    }
    switch(dir){
      case 0: _x++; break;
      case 1: _y++; break;
      case 2: _x--; break;
      case 3: _y--; break;
    }
  }
  std::cout << turns << std::endl;

  return 0;
}

