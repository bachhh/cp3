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
  int x[200];
  int y[200];
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  int output = 0;
  for (int i = 0; i < n; ++i) {

    bool l, r, u, d;
    l = r = u = d = false;
    for (int j = 0; j < n; j++) {
      if (j==i) continue;
      if (x[i] == x[j] && y[i] < y[j])
        u = true;
      if (x[i] == x[j] && y[i] > y[j])
        d = true;
      if (y[i] == y[j] && x[i] < x[j])
        r = true;
      if (y[i] == y[j] && x[i] > x[j])
        l = true;
    }
    if (l && r && u && d) output++;
  }
  std::cout << output << std::endl;

  return 0;
}

