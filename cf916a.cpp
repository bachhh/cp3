#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

bool isLucky(int h, int m){
  if (m%10 == 7 || (m/10) == 7 ) return true;
  if (h%10 == 7 || (h/10) == 7 ) return true;
  return false;
}

void decrease(int &h, int &m, int step){
  m -= step;
  if (m < 0){
    h -= 1;
    if (h < 0){
      h += 24;
    }
    m += 60;
  }
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int x; cin >> x;
  int h, m; cin >> h >> m;
  int counter = 0;
  while(isLucky(h, m) == false){
    counter++;
    decrease(h, m, x);
  }
  std::cout << counter << std::endl;


  return 0;
}

