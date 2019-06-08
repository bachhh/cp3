#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int32_t n; cin >> n;

  int digit = floor(log10(n))+1;

  int64_t counter = 0;

  while(digit>0){
    counter += (n-pow(10, digit-1)+1)*digit;
    n = (int32_t)pow(10, digit-1)-1;
    digit--;
  }
  std::cout << counter << std::endl;

  return 0;
}


