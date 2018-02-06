#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int64_t a[5];
  int64_t sum = 0;
  for (int i = 0; i < 5; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  int64_t maxsum = -1, minsum = INT64_MAX;

  for (int i = 0; i < 5; ++i) {
    if (sum - a[i] > maxsum){
      maxsum = sum-a[i];
    }

    if(sum - a[i] < minsum){
      minsum = sum - a[i];
    }
  }

  std::cout << minsum  << " " << maxsum << std::endl;

  return 0;
}

