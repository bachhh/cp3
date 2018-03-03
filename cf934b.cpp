#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int k;
  cin >> k;
  int64_t output = 0;
  map<int, int> loop;

  loop[8] = 2;
  loop[9] = 1;
  loop[0] = 1;
  loop[4] = 1;
  loop[6] = 1;
  loop[5] = 0;
  loop[7] = 0;
  loop[1] = 0;
  loop[2] = 0;
  loop[3] = 0;
  if(k> 2*18){
    output = -1;
  }
  else {
    while(k>0){
      if(k%2){
        output = output * 10+ 4;
        k--;
      }
      else {
        output = output*10+8;
        k -= 2;
      }
    }
  }
  std::cout << output << std::endl;

  return 0;
}

