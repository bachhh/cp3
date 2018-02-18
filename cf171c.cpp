#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){

  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int a0;
  int a;
  cin >> a0;

  int64_t output = 0;
  for (int i = 1; i <= a0; ++i) {
    cin >> a;
    output += i*a;
  }
  std::cout << output << std::endl;

  return 0;
}

