#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int tc; cin >> tc;
  while(tc--){
    int n; cin >> n;
    int p; cin >> p;
    vector<bool> sim(n+1, false);
    for (int i = 0; i < p; i++) {
      int h; cin >> h;
      for (int j = 0; j*h <= n; ++j) {
        if( (j*h-6)%7 == 0 || j*h %7 == 0) continue;
        sim[j*h] = true;
      }
    }
    int counter = 0;
    for (int i = 1; i <= n; i++) {
      if (sim[i]) counter++;
    }
    std::cout <<  counter << std::endl;
  }

  return 0;
}

