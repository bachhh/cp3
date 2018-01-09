#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int64_t n, k;
  cin >> n >> k;
  //
  if (k == 1){
    std::cout << n << std::endl;
  }
  else {

    // for each 0 bit of n from the most significant bit
    // turn on k of them until we reach 1<<bit - 1

    int bit;
    for (bit = 1; bit < 64; ++bit) {
      if(n < ((int64_t)1)<<bit ){
        break;
      }
    }

    std::cout << (((int64_t)1)<<bit) - 1 << std::endl;
  }

  return 0;
}

