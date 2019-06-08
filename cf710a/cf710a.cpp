#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  char c, d;
  cin >> c >> d;
  if(c=='a' || c == 'h'){
    if(d == '8' || d == '1')
      std::cout << 3 << std::endl;
    else
      std::cout << 5 << std::endl;
  }
  else if (d == '8' || d == '1'){
    std::cout << 5 << std::endl;
  }
  else {
    std::cout << 8 << std::endl;
  }

  return 0;
}

