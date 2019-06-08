#include <bits/stdc++.h>

using namespace std;

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define LIMIT 100


//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int x, y;
  cin >> x >> y;
  int t[3] = {y, y, y};

  int counter = 0;
  while(  !(t[0] == x && t[1]  == x && t[2] == x )){
    sort(t, t+3);
    t[0] = MIN(t[1]+t[2]-1 , x);
    counter++;
  }
  std::cout << counter << std::endl;

  return 0;
}

