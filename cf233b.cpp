#include <bits/stdc++.h>

using namespace std;


#define LIMIT 100

int sumDig(int64_t a){
  int r = 0;
  while(a>0){
    r += a%10;
    a /= 10;
  }
  return r;
}
//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int64_t n; cin >> n;
  int64_t sx;

  int64_t v[91] = {-1};

  // delta = sx^2 + 4*n
  for (sx = 1; sx < 90; ++sx){
    int64_t dsqrt = sqrt(sx*sx+4*n);
    if(dsqrt*dsqrt == sx*sx+4*n){
      int64_t roottwice = (-sx+dsqrt);
      if( roottwice%2 == 0 && sumDig(roottwice/2) == sx ){
        v[sx] = roottwice/2;
      }
    }
  }
  int64_t output = LLONG_MAX;

  for (int i = 0; i < 91; i++) {
    if(v[i] > 0){
      output = min(output, v[i]);
    }
  }

  if(output < LLONG_MAX){
    std::cout << output << std::endl;
  }
  else{
    std::cout << -1 << std::endl;
  }


  return 0;
}

