#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k; cin >> n >> k;

  //std::cout << "TESt" << std::endl;

  int a, total = k;
  int accum = 0;
  int date = 0;

  for (int i = 0; i < n; i++) {
    cin >> a;
    accum += a;
    int give = min(8,accum);
    k -= give;
    date++;
    if (k <= 0){
      return std::cout << date << std::endl, 0;
    }
  }

  std::cout << -1 << std::endl;
  return 0;
}

