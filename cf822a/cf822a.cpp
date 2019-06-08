#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
#define MIN(a, b) (a<b?a:b)

int64_t factorial(int64_t n){
  if(n == 1) return 1;
  else return n*factorial(n-1);
}
//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int32_t a, b; cin >> a >> b;
  std::cout << factorial(MIN(a, b)) << std::endl;

  return 0;
}

