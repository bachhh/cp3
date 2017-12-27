#include <bits/stdc++.h>

using namespace std;

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int tc; cin >> tc;

  /* if y % 2 == 0 */
  /*   x^y = (x^2)^y/2 */
  /* else */
  /*   x^y = (x*x)^(y-1) */

  int64_t x, y, n;
  while(tc--){
    cin >> x >> y >> n;
    int64_t r = 1;
    if (y == 0){
      std::cout << 1 << std::endl;
      continue;
    }

    while(y>0){
      if (y%2 == 1){
        r = (r*x)%n;
      }
      x = (x*x)%n;
      y = y >> 1;
    }
    std::cout << r << std::endl;
  }

  return 0;
}

