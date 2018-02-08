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

  int ma = INT_MIN, mi = INT_MAX;
  int v[100];

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    ma = max(ma, v[i]);
    mi = min(mi, v[i]);
  }

  int counter = 0;

  int i;
  for (i = 0; i < n; ++i) {
    if(v[i] == ma)
      break;
  }
  while(i > 0){
    counter++;
    swap(v[i], v[i-1]);
    i--;
  }

  for (i = n-1; i >= 0; --i) {
    if(v[i] == mi) break;
  }

  while(i+1 < n){
    counter++;
    swap(v[i], v[i+1]);
    i++;
  }

  std::cout << counter << std::endl;

  return 0;
}

