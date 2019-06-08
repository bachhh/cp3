#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int m, b;
  cin >> m >> b;

  int64_t output = 0;

  for (int64_t x = 0; x <= m*b; ++x) {
    int64_t y = (double)-x/m + b;
    //std::cout << x << "|" << y << std::endl;
    int64_t x_sum = x*(x+1)/2;
    int64_t y_sum = y*(y+1)/2;
    //std::cout << std::endl;
    output = max<int64_t>(x_sum*(y+1) + y_sum*(x+1), output);
  }
  std::cout << output << std::endl;

  return 0;
}

