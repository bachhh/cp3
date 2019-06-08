#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100


bool isPerfect(int a){
  int output = 0;
  while(a > 0){
    output += a%10;
    a /= 10;
  }
  return output == 10;
}

//  ***** MAIN *****
int main(){

  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int k; cin >> k;
    int f = 10;
    int i = k;
    while(i){
      f += 9;
      if (isPerfect(f)){
        i--;
      }
    }
    std::cout << f << std::endl;


  return 0;
}

