#include <bits/stdc++.h>

using namespace std;

#define LIMIT 1000

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int v[6] = {0};
  int total = 0;
  for (int i = 0; i < 6; i++) {
    cin >> v[i];
    total += v[i];
  }

  for (int mask = 0; mask < (1<<7); ++mask) {
    int sum =0;
    for (int bit = 0; bit < 7; ++bit) {
      if(mask & (1<<bit)){
        sum += v[bit];
      }
    }
    if (sum == total-sum){
      std::cout << "YES" << std::endl;
      return 0;
    }
  }
  std::cout << "NO" << std::endl;
  return 0;
}

