#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9
#define LIMIT 2001


//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int64_t n, x1, x2, y1, y2;
  cin >> n >> x1 >> y1 >> x2 >> y2;

  vector<pair<int64_t, int64_t>> v(n);
  int64_t x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    v[i].first = (x-x1)*(x-x1) + (y-y1)*(y-y1);
    v[i].second= (x-x2)*(x-x2) + (y-y2)*(y-y2);
  }

  v.push_back({0, 0});
  // Caculate line F1F2
  // ax + by + c = 0
  int64_t m = INT64_MAX;
  for (auto i : v) {
    int64_t d1 = i.first;
    int64_t d2max = 0;
    for (auto j : v) {
      if(j.first > d1) d2max = max(d2max, j.second);
    }
    m = min(m, d1+d2max);
  }


  std::cout << m << std::endl;


  return 0;
}

