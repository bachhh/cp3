#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  while(tc--){
    int n;
    cin >> n;
    int v[500];
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }
    int mind = INT_MAX;
    for (int i = 0; i < 30000; ++i) {
      long long d = 0;
      for (int j = 0; j < n; ++j) {
        d += (abs(v[j] - i));
      }
      mind = min<long long>(d, mind);
    }
    std::cout << mind << std::endl;
  }

  return 0;
}

