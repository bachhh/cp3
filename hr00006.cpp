#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  int h;

  int consec = 0;
  int maxh = -1;
  for (int i = 0; i < n; ++i) {
    cin >> h;
    if(h > maxh ){
      consec = 1;
      maxh = h;
    }
    else if(h == maxh ){
      consec++;
    }
  }
  std::cout << consec << std::endl;

  return 0;
}

