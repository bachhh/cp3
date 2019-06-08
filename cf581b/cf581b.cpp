#include <bits/stdc++.h>

using namespace std;

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define LIMIT 100000

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  int32_t h[LIMIT];
  int32_t m[LIMIT];
  int32_t ma = 0;

  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }

  for (int i = n-1; i >= 0; --i){
    m[i] = ma;
    ma = max(h[i], ma);
  }

  for (int i = 0; i < n; i++) {
    std::cout << MAX(m[i] + 1 - h[i], 0) << std::endl;

  }



  return 0;
}

