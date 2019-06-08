#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  double n, x, y;
  cin >> n >> x >> y;

  int c = ceil((y*n-100*x)/100);
  std::cout << max(0, c) << std::endl;

  return 0;
}

