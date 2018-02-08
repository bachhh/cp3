#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int k;
  cin >> k;
  int a[12];

  for (int i = 0; i < 12; ++i) {
    cin >> a[i];
  }

  sort(a, a+12, greater<int>());

  int i = 0;
  int total =0;

  for(i = 0; i < 12; ++i ){
    if (total >= k) break;
    total += a[i];
  }

  if (total >= k) std::cout << i << std::endl;
  else std::cout << -1 << std::endl;


  return 0;
}

