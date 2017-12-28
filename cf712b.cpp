#include <bits/stdc++.h>

using namespace std;

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define LIMIT 100000

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  char c;

  int up = 0;
  int down = 0;
  int left = 0;
  int right = 0 ;

  while(cin >> c){

    switch (c) {
      case 'U': up++;
                break;
      case 'D': down++;
                break;
      case 'L': left++;
                break;
      case 'R': right++;
                break;
    }
  }

  if ( (up + down + left+right)%2 != 0  ){
    std::cout << -1 << std::endl;
  }
  else {
    std::cout <<  (abs(left-right) + abs(up-down))/2 << endl;
  }

  return 0;
}

