#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

typedef pair<int64_t, int64_t> ii;

vector<ii> ppl;
vector<ii> cost;
vector<int64_t> vol;
int64_t n, l;

int64_t cheapest(int64_t volume){
  if (volume <= 0) return 0;
  int64_t right = INT64_MAX;

  // min cost for bottle larger or equal to volume
  for (int i = 0; i < n; i++) {
    if (( volume <= (((int64_t)1)<<cost[i].second))){
      right = min(cost[i].first, right);
    }
  }

  // mincost for buying bottle(s) smaller than volume
  int64_t left = INT64_MAX;
  int bottle = -1;
  // pick the best price per-litre bottle of < volume
  for (int i = 0; i < n ; ++i) {
    if ( volume > (((int64_t)1)<<ppl[i].second)) {
      bottle = ppl[i].second;
      left = ppl[i].first * (volume>>ppl[i].second);
      volume %= (volume>>ppl[i].second)*(((int64_t)1)<<bottle);
      break;
    }
  }

  //std::cout << volume << " | " << left << " | " << right << std::endl;
  if (right <= left){
    return right;
  }
  else {
    left += cheapest( volume );
    return min(right, left);
  }
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> l;
  int64_t c;

  for (int i = 0; i < n; i++) {
    cin >> c;
    cost.push_back({c, i});
    ppl.push_back({c, i});
    vol.push_back((int64_t)1<<i);
  }

  sort(cost.begin(), cost.end(), [](ii a, ii b){
                        return a.first < b.first;
      });


  sort(ppl.begin(), ppl.end(), [](ii a, ii b){
                              return ((double)(a.first))/(1<<(a.second)) <
                                  (((double)(b.first))/(1<<(b.second)));
    });


  std::cout << cheapest(l) << std::endl;


  return 0;
}


