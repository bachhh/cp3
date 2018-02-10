#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int64_t n, m;
  cin >> n >> m;

  int64_t xc, yc;
  cin >> xc >> yc;
  int k; cin >> k;

  int64_t dx;
  int64_t dy;

  int64_t counter = 0;
  for (int i = 0; i < k; ++i) {
    cin >> dx >> dy;
    int64_t up, down, left, right;
    up = down = left = right = INT64_MAX;
    if (dx > 0){
      right = (n-xc)/dx;
    }
    if(dx<0){
      left = ( -xc+1 )/dx;
    }
    if (dy > 0 ){
      up = (m-yc)/dy;
    }
    if (dy< 0){
      down = ( -yc+1 )/dy;
    }

    int t = min<int64_t>(up,
          min<int64_t>(down,
          min<int64_t>(left, right)));
    //std::cout << t << std::endl;
    xc += t*dx;
    yc += t*dy;

    counter += t;
  }

  std::cout << counter << std::endl;

  return 0;
}

