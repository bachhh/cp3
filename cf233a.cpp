#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  if (n%2){
    std::cout << -1 << std::endl;
  }
  else {
    for (int i = 1; i <= n/2; i++) {
      std::cout << i*2 << " ";
      std::cout << i*2-1 << " \n"[i==n/2];
    }

  }

  return 0;
}

