#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;

  vector<ii> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first >> v[i].second;
  }

  sort(v.begin(), v.end(),
      [ ] (ii a, ii b)
      {
        if(a.second != b.second)
          return a.second > b.second;
        else
          return a.first > b.first;
      }
  );
  int counter = 1;
  int output = 0;
  for (int i = 0; counter > 0 && i < n; ++i) {
    counter += v[i].second -1;
    output += v[i].first;
  }
  std::cout << output << std::endl;


  return 0;
}
