#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

double hornerRoot(const double guess,
                  const int rep,
                  double* coef,
                  const int degree) {
  double x = guess;
  for (int i = 0; i < rep; ++i) {
    double p = 0;
    double dp = 0;
    for (int i = degree; i>= 0; --i) {
      dp = dp*x + p;
      p = p * x + coef[i];
    }
    x -= p/dp;
  }
  return x;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  double coef[4] = {-1, 2, -6, 2};
  int degree = 3;

  // input

  return 0;
}

