#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int32_t a[200001];
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a+n);
  int32_t output = INT32_MAX;
  for (int i = 0; i < n-1; i++) {
    output = min(output,abs(a[i] - a[i+1]));
  }
  std::cout << output << std::endl;




  return 0;
}

