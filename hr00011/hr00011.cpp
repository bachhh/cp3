#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int x1, v1, x2, v2;

  cin >> x1 >> v1 >> x2 >> v2;
  if( (x1 > x2 && v1 >= v2 )||
      (x2 > x1 && v2 >= v1)){
    std::cout << "NO" << std::endl;
  }
  else if (abs(x2-x1)%(max(v1, v2) - min(v2, v1)) == 0){
    std::cout << "YES" << std::endl;
  }
  else {
    std::cout << "NO" << std::endl;
  }



  return 0;
}

