#include <bits/stdc++.h>

using namespace std;


#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  vector<ii> a(n);
  vector<ii> b(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }

  int m; cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> b[i].first >> b[i].second;
  }

  return 0;
}

