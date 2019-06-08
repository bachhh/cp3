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
  int a[100];

  int64_t miCost = INT64_MAX;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = -100; i <= 100; ++i) {
    int64_t cost = 0;
    for (int j = 0; j < n; ++j) {
      cost += (a[j]-i)*(a[j]-i);
    }
    miCost = min<int64_t>(cost, miCost);
  }
  std::cout << miCost << std::endl;

  return 0;
}

