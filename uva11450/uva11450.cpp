#include <bits/stdc++.h>

using namespace std;
#define LIMIT 100


//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int m, c;
  int g, money, k;
  int price[30][30];
  bool reachable[25][210];

  int tc; cin >> tc;
  while(tc--){
    cin >> m >> c;
    for (g = 0; g < c; ++g) {
      cin >> price[g][0];
    }

    if (output < 0 )  std::cout << "no solution" << std::endl;
    else              std::cout << output << std::endl;

  }


  return 0;
}

