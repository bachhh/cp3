#include <bits/stdc++.h>

using namespace std;

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define LIMIT 100000

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int64_t n, k;
  cin >> n >> k;
  int64_t a[LIMIT];

  int64_t rate = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    rate += a[i]/10;
    a[i] = 10-(a[i]%10);
  }
  sort(a, a+n);

  int64_t i = 0;

  while(a[i] != 0 && k >= a[i] && i < n){
    k -= a[i];
    i++;
  }

  std::cout << MAX(0, k/10) + i +rate << std::endl;


  return 0;
}

