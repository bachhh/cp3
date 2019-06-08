#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  double a, d;

  cin >> n >> a >> d;
  double maxt = -1;

  for (int i = 0; i < n; ++i) {

    double v;
    int t0;
    cin >> t0 >> v;

    double t;

    if (d > (v*v)/(2.0*a) ){
      t  = v/a + d/v - v/(2.0*a) + t0;
    }
    else {
      t = sqrt((d*2.0)/a) + t0;
    }


    if (t < maxt){
      printf("%.12f\n", maxt);
    }
    else{
      maxt = t;
      printf("%.12f\n", maxt);
    }

  }

  return 0;
}

