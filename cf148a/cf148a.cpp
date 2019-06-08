#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int k , l, m, n, d;
  cin >> k  >> l >> m >> n >> d;
  int counter = 0;
  for (int i = 1; i <= d; ++i) {
    if (i%k == 0){
      counter++;
      continue;
    }
    if (i%l == 0){
      counter++;
      continue;
    }
    if (i%m == 0){
      counter++;
      continue;
    }
    if (i%n == 0){
      counter++;
      continue;
    }

  }
  std::cout << counter << std::endl;

  return 0;
}

