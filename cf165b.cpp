#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

int64_t n, k;

int64_t solve(int64_t v){
  int64_t output = 0;
  int64_t p = 1;
  while(v/p > 0){
    output += v/p;
    p *= k;
  }
  return output;
}
//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >>  n >> k;

  int64_t l = 0;
  int64_t h = 1000000000;

  while(l< h){
    int64_t m = l + (h-l)/2;
    if(solve(m) < n){
      l = m+1;
    }
    else {
      h = m;
    }
  }
  if (solve(l) >= n){
    std::cout << l << std::endl;
  }

  return 0;
}
