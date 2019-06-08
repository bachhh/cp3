#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  int a[51][51];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] > 1){
        bool found = false;

        for (int k = 0;!found && k < n; ++k) {
          if (k==i) continue;
          int x = a[k][j];
          for (int l = 0; !found && l < n; ++l) {
            if (l == j) continue;
            int y = a[i][l];
            if(x+y==a[i][j]){
              found = true;
            }
          }
        }
        if (!found){
          std::cout << "No" << std::endl;
          return 0;
        }
      }
    }
  }
  std::cout << "Yes" << std::endl;

  return 0;
}

