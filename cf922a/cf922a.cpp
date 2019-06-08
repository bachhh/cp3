#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int x, y;

  cin >> x >> y;

  int copies = x - y + 1;

  if (copies < 0 || y == 0){
    std::cout << "No" << std::endl;
  }
  else if (copies % 2 == 0){
    std::cout << "Yes" << std::endl;
  }
  else {
    std::cout << "No" << std::endl;
  }

  return 0;
}

