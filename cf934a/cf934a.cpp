#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >>n >> m;

  ll a[100000];
  ll b[100000];

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  ll tommy = INT64_MAX;

  for (int i = 0; i < n; ++i) {
    ll banban = INT64_MIN;
    for (int j = 0; j < n; ++j) {
      if(j == i ) continue;

      for (int k = 0; k < m; ++k) {
        banban =  max<ll>(banban, a[j] * b[k]);
      }
    }
    tommy = min<ll>(tommy, banban);
  }

  std::cout << tommy << std::endl;

  return 0;
}

