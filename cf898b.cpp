#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int64_t a, b, n;
  cin >> n >> a >> b;
  int64_t x = 0, y;

  for(x = 0; x <= n/a; ++x ){
    y = (n-x*a)/b;
    if (x*a + y*b == n){
      std::cout << "YES" << std::endl;
      std::cout << x << " " << y << std::endl;
      return 0;
    }

  }
  std::cout << "NO" << std::endl;

  return 0;
}

