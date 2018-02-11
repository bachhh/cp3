#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  int c[10000];

  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  int mi = c[0];
  int ma = c[0];

  int output = 0;
  for (int i = 1; i < n; ++i) {
    if (c[i] > ma){
      ma = c[i];
      output++;
    }
    if (c[i] < mi){
      mi = c[i];
      output++;
    }
  }
  std::cout << output << std::endl;

  return 0;
}

