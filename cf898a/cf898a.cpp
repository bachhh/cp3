#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int64_t n;
  cin >> n;
  if(n%10 < 5){
    n -= n%10;
  }
  else{
    n += 10-n%10;
  }
  std::cout << n << std::endl;

  return 0;
}

