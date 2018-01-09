#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int64_t n, m;
  cin >> n >> m;

  if (n > 26){
    std::cout << m << std::endl;
  }
  else {
    m -= ((m>>n)<<n);
    std::cout << m << std::endl;
  }

  return 0;
}

