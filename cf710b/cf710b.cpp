#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int32_t v[300001];
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v, v+n);
  std::cout << v[(n+1)/2-1] << std::endl;

  return 0;
}

