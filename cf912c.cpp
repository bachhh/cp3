#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100001


/* @@@ NOTE @@@
 * So essentially i'm translating everything to a graph
 * of money against time, and finding the optimum point of that graph
 *
 */
//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;

  int32_t bounty, increase, damage;

  cin >> bounty >>  increase >>  damage;

  int32_t max_health[LIMIT];
  int32_t start_health[LIMIT];
  int32_t regen[LIMIT];

  map<int32_t, int64_t> moneytime;
  int64_t start = 0;
  int64_t counter = 0;

  // we define break point as the
  for (int i = 0; i < n; i++) {
    cin >> max_health[i] >> start_health[i] >> regen[i];
    if (max_health[i] < damage && increase > 0){
      std::cout << -1 << std::endl;
      return 0;
    }
    if (start_health[i] <= damage){
      // we define break point as the point t
      // were health[t] > damage and health[t-1] <= damage
      int32_t bp = (damage- start_health[i])/regen[i] +1 ;
      if (bp > 0){
        moneytime[0]++;
        moneytime[bp]--;
        moneytime[bp-1] += 0;
      }
    }
  }

  int32_t t, e, h;
  for (int i = 0; i < m; i++) {
    cin >> t >> e >> h; e--;
    int32_t bp = (damage - start_health[e])/regen[e] + 1; // "breakpoint"
    int32_t newbp = t+max(0, (damage - h)/regen[e]+1);
    if (bp > 0 && t <= bp){
      moneytime[bp]++;
    }
    else if (t > bp){
      if (h <= damage) moneytime[t]++;
    }
    moneytime[newbp]--;
    moneytime[newbp-1] += 0;
  }

  int64_t mx = 0;

  int64_t ecounter = 0;
  for (auto p = moneytime.begin(); p != moneytime.end(); ++p) {
    ecounter += p->second;
    int32_t t = p->first;
    mx = max(mx, ecounter*(bounty + t*increase));
  }
  std::cout << mx << std::endl;

  return 0;
}

