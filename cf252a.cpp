#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;

  int64_t x[100];

  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  int64_t ma = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; j++) {
      int64_t e = x[i];
      for (int k = i+1; k <= j ; ++k) {
        if (j==i) break;
        e ^=  x[k];
      }
      ma = max<int64_t>(ma, e);
    }
  }

  std::cout << ma << std::endl;

  return 0;
}

