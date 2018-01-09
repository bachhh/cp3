#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int64_t n, m;
  cin >> n >> m;

  if ( log2(m) > n){
    std::cout << m% ((int64_t)(1<<n)) << std::endl;
  }
  else {
    std::cout << m << std::endl;
  }

  return 0;
}

