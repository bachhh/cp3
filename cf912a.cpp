#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int64_t a, b, x, y, z;
  cin >>a >>  b >>  x >>  y >>  z;

  int64_t _a = 2*x + y;
  int64_t _b = 3*z + y;

  std::cout << max<int64_t>(_a - a, 0) + max<int64_t>(_b - b, 0) << std::endl;

  return 0;
}

