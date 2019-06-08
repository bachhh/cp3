#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

int64_t dezero(int64_t i){
  int64_t temp = 0, output = 0;
  while(i > 0){
    if (i%10){
      temp += i%10;
      temp *= 10;
    }
    i /= 10;
  }
  temp/=10;
  while(temp>0){
    output += temp%10;
    temp /= 10;
    output *= 10;
  }
  return output/10;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int64_t a, b, c, _a, _b, _c;
  cin >> a >> b;
  c = a+b;
  _a = dezero(a), _b = dezero(b);
  _c = _a + _b;

  if (dezero(c) == _c) {
    std::cout << "YES" << std::endl;
  }
  else {
    std::cout << "NO" << std::endl;
  }


  return 0;
}

