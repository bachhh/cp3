#include <bits/stdc++.h>

using namespace std;

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define LIMIT 100

int sumDigit(int64_t x){
  int r = 0;
  while(x>0){
    r += x%10;
    x /= 10;
  }
  return r;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int64_t n; cin >> n;

  int64_t high = n;
  int64_t low = 1;
  int64_t mid;

  while(high > low){
    mid = low+ (high-low)/2;
    if ((pow(mid,2) + sumDigit(mid)*mid) >= n ){
      high = mid;
    }
    else {
      low = mid+1;
    }
  }
  low = 9;
  std::cout << pow(low,2) + sumDigit(low)*low << std::endl;
  std::cout << low << std::endl;

  return 0;
}

