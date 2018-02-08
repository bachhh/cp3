#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int r1, r2, c1, c2, d1, d2;
  cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;

  int gem[4] ={0};
  bool found = false;
  for (int i = 1;!found && i < 10; ++i) {
    for (int k = 1; !found && k < 10; ++k) {
      for (int l = 1; !found && l < 10; ++l) {
        for (int m = 1; !found && m < 10; ++m) {
          if (i== k || i == l || i == m){ continue; }
          if (k == l || k == m){ continue; }
          if (l == m) continue;

          if (i + k == r1 && l + m == r2
            && i+l == c1 && k + m == c2
            && i+ m == d1 && k+l == d2){
            gem[0] = i; gem[1] = k; gem[2] = l; gem[3] = m;
            found = true;
          }
        }
      }
    }
  }
  if (!found){
    std::cout << -1 << std::endl;
    return 0;
  }
  for (int i = 0; i < 4; ++i) {
    std::cout << gem[i] << " \n"[i%2==1];
  }

  return 0;
}

