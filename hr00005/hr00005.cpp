#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;

  for (int i = 0; i < n; ++i) {
    std::cout << string(n-i-1, ' ');
    std::cout << string(i+1, '#') << std::endl;
  }

  return 0;
}

