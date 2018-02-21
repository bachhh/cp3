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
  int output = 0;
  for (int i = 1; i <= n; ++i) {
    output += i;
  }
  std::cout << output << std::endl;

  return 0;
}

