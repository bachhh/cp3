#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;

int x[100];


//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, d;

  cin >> n >> d;


  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  sort(x, x+n);
  int ma = -1;

  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (x[j] - x[i] <= d){
        ma = max(ma, j-i+1);
      }
    }
  }

  std::cout << n-ma << std::endl;

  return 0;
}

