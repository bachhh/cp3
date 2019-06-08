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
  int a[100];

  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }

  sort(a, a+n,
      [ ](int a, int b){
      return a > b;
  });

  int total = 0;
  int i =0;
  for (i = 0;total <= sum-total &&  i < n; ++i) {
    total += a[i];
  }
  std::cout << i << std::endl;
  return 0;
}

