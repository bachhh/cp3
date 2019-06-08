#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int32_t w, m;
  cin >> w >> m;
  // convert m to  base W
  string mstr = "";

  while(m>0){
    mstr.insert(0,1, m%w + '0');
    m /= w;
  }

  std::cout << mstr << std::endl;

  return 0;
}

