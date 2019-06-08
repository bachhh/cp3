#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

typedef tuple<int32_t,int32_t,int32_t> iii;

bool proposition(int x, iii a, iii b){
  if(get<0>(b) <= get<1>(a)){
    return false;
  }
  else{
    return get<1>(a)-get<0>(a) +get<1>(b)-get<0>(b)+1 == x;
  }
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, x;
  cin >> n >> x;
  int32_t a, b, c;
  vector<iii> v;

  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c;
    v.push_back(iii(a, b, c));
  }

  // Sort by duration first, and then cost
  sort(v.begin(), v.end(), [](iii a, iii b){
                          int32_t dura = get<1>(a) - get<0>(a);
                          int32_t durb = get<1>(b) - get<0>(b);
                        if (get<0>(a) != get<0>(b)){
                          return get<0>(a) < get<0>(b);
                        }
                        else if( dura != durb ){
                          return dura < durb;
                        }
                        else{
                          return get<2>(a) < get<2>(b);
                        }
      });

  for (auto i : v) {

    // Find the first:
      // # non-overlapping
      // correct duration
      //
  }

  return 0;
}

