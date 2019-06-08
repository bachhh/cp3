#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;

  string s, t; cin >> s >> t;

  int min_diff = INT_MAX;
  vector<int> min_v;

  for (int i = 0; i < m-n+1; i++) {
    int diff = 0;
    vector<int> v;
    for (int j = 0; j < n; j++) {
      if (s[j] != t[i+j]){
        diff++;
        v.push_back(j+1);
      }
    }

    if (diff< min_diff){
      min_diff = diff;
      min_v = v;
    }

  }

  std::cout << min_diff << std::endl;
  for (int i = 0; i < min_v.size(); i++) {
    std::cout << min_v[i] << " \n"[i==min_v.size()-1];
  }

  return 0;
}

