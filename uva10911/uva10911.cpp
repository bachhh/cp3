#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
#define INF 1e9

int n;
double dp[65540];

class Point{
  public:
    double x, y;
    Point(void ) : x(0), y(0){}
    Point(double _x, double _y) : x(_x), y(_y) {}
};

vector<Point> d;

double solve(int mask){
  if (mask >= (1<<(2*n))-1){
    return 0;
  }

  if(dp[mask] != -1) return dp[mask];
  double output = INF;

  for (int i = 0; i < n*2; i++) {
    if(mask & 1<<i) continue;
    for (int j = i+1; j < n*2; j++) {

      if (mask & 1<<j) continue;

      double dist = hypot(d[i].x - d[j].x,
            d[i].y - d[j].y) + solve( mask | ((1<<i) + (1<<j)) );
      output = min(output, dist);
    }
  }
  return dp[mask] = output;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  double x, y;
  int tcn = 1;
  string temp;
  while(cin >> n && n){
    d.clear();
    for (int i = 0; i < 65540; i++) { dp[i] = -1; }

    for (int i = 0; i < n*2; i++) {
      cin >> temp >> x >> y;
      d.push_back(Point(x, y));
    }

    printf("Case %d: %.2f\n", tcn++, solve(0));
  }

  return 0;
}

