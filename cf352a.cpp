#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, a;
  cin >> n;
  int five = 0, zero = 0;
  for (int i = 0; i < n; i++) {
    cin >> a;
    switch(a){
      case 0: zero++; break;
      case 5: five++; break;
    }
  }

  // at least 9 five and 1 zero
  if (five/9 <1 ){
    if (zero < 1) std::cout << -1 << std::endl;
    else if(zero >= 1 ) std::cout << 0 << std::endl;
    return 0;
  }

  for (int i = 0; i < five-five%9; i++) {
    std::cout << 5;
  }

  for (int i = 0; i < zero; i++) {
    std::cout << 0;
  }




  return 0;
}

