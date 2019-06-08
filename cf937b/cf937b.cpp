#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;
int gcd(int a, int b){ return  (b==0)?a:gcd(b, a%b);}
int lcm(int a, int b) { return a*b/(gcd(a,b)); }


bool check(long y,  long p){
  for(long i = 2; i*i<=y && i <= p; ++i){
    if (y %i == 0 ) return false;
  }
  return true;
}
//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  long p, y;
  cin >> p >> y;

  while(y > p ){
    if (check(y, p)) break;
    else y--;
  }
  if (y > p) {
    std::cout << y << std::endl;
  }
  else {
    std::cout << -1 << std::endl;
  }

  return 0;
}

