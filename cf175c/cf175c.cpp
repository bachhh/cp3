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

  vector<ii> kc(n);

  for (int i = 0; i < n; ++i) {
    cin >> kc[i].first >> kc[i].second;
  }
  sort(kc.begin(), kc.end(),
      [ ] (ii a, ii b) {
        return a.second < b.second;
      }
      );

  int t;
  cin >> t;

  vector<int64_t> p(t+2);
  for (int i = 1; i <= t; ++i) {
    cin >> p[i];
  }

  p[t+1] = INT64_MAX;

  int64_t f = 1;
  int64_t destroyed = 0;
  int64_t score = 0;

  for (int i = 0; i < n; ++i) {

    if (destroyed + kc[i].first < p[f] ){
      score += kc[i].second*kc[i].first*f;
      destroyed += kc[i].first;
    }
    else {
      score += kc[i].second* (p[f] - destroyed)*f;

      kc[i].first = (destroyed + kc[i].first - p[f]);
      destroyed = p[f];
      i--;
      f++;
    }
  }

  std::cout << score << std::endl;

  return 0;
}

