#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
#define EPS 1e-9
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int64_t a, x, y;
  cin >> a >> x >> y;
  if (y % a == 0){
    std::cout << -1 << std::endl;
  }
  else if (y < 2*a){

    if ((double)x > a/2.0-EPS || x < -a/2.0 + EPS){
      std::cout << -1 << std::endl;
    }
    else{
      std::cout << y/a+1 << std::endl;
    }
  }
  else if( (y/a)%2 == 1){
    if ((double)x > a/2.0-EPS || x < -a/2.0 + EPS){
      std::cout << -1 << std::endl;
    }
    else{
      int64_t base = 5 + 3 * (y/a-3)/2;
      std::cout << base  << std::endl;
    }
  }
  else if ( (y/a)%2 == 0){
    if (x >=  a || x <= -a ){
      std::cout << -1 << std::endl;
    }
    else if ( x == 0){
      std::cout << -1 << std::endl;
    }
    else{
      int64_t base = 3 + 3 * (y/a-2)/2;
      std::cout << (base + (x>0) )<< std::endl;
    }
  }
  else {
  }

  return 0;
}

