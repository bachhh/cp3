#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  int a[1000];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int counter = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; j++) {
      if((a[i]+a[j])%k == 0)counter++;
    }
  }
  std::cout << counter << std::endl;

  return 0;
}

