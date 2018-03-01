#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;
#define EPS 1e-9

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  double x1, y1, r1;
  double x2, y2, r2;
  cin >> x1 >> y1 >> r1;
  cin >> x2 >> y2 >> r2;

  double d = hypot(x1-x2, y1-y2);

  if(d < r1 || d < r2){
    d = max<double>(r1, r2) -d- min<double>(r1, r2);
    d /= 2.0;
  }
  else if (d-r1-r2 > EPS){
    d = (d-r1-r2)/2.0;
  }
  else {
    d = 0;
  }

  printf("%.8f\n",max(0.0, d));

  return 0;
}

