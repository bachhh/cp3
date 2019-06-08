#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int64_t s, t, a, b, m, n;
  cin >> s >> t >> a >> b >> m >> n;

  int64_t suma = 0, sumb = 0;
  int64_t temp;

  for (int i = 0; i < m; ++i) {
    cin >> temp;
    if ( a+temp >= s && a+temp <= t){
      suma++;
    }
  }

  for (int i = 0; i < n; ++i) {
    cin >> temp;
    if ( b+temp >= s && b+temp <= t ){
      sumb++;
    }
  }

  std::cout << suma << std::endl;
  std::cout << sumb << std::endl;
  return 0;
}

