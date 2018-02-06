#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int64_t a;
  int64_t output = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    output += a;
  }
  std::cout << output << std::endl;

  return 0;
}

