#include <bits/stdc++.h>

using namespace std;
#define LIMIT 100001
#define EPS 1e-9

double dist(double x1,double y1, double x2,double y2){
  return hypot(x1-x2, y1-y2);
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int ax, ay, bx, by, tx, ty;
  int n;
  int x, y;

  cin >> ax >>  ay >>  bx >>  by >>  tx >>  ty;
  cin >> n;

  vector<pair<double, int>> a;
  vector<pair<double, int>> b;
  double total = 0.0;

  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    double d = dist(x, y, tx, ty);
    total += 2*d;
    a.push_back(pair<double, int>(dist(x, y, ax, ay) - d, i));
    b.push_back(pair<double, int>(dist(x, y, bx, by) - d, i));
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  double output = 1e30;

  // Optimum of only A
  output = min(output, total + a[0].first);
  // Optimum of only B
  output = min(output, total + b[0].first);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i].second != b[j].second){
        // Minimum of a combination of optimum of both A B
        output = min(output, total + a[i].first + b[i].first);
      }
    }
  }
  printf("%.10lf\n", output);


  return 0;
}

