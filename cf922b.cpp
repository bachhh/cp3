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

  int counter = 0;

  for (int a = 1; a <= n; ++a) {
    for (int b = a; b <= n; ++b) {
      if ( (a^b) < a+b ) {
        printf("%d %d \n", a, b);
        counter++;
      }
    }
  }

  std::cout << counter << std::endl;

  return 0;
}

