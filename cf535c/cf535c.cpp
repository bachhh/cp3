#include <bits/stdc++.h>

using namespace std;

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define LIMIT 10000

//### I kept mispselling karaf to carrot, is this pun intended ?


/* Time taken to fully eat the POSth Karaf
 * total time <= m*t
 * total time = a+ (l-1)*b + a + (l-2)*b + ... + a + (r-1)*b
 */

bool canFinished(int64_t a, int64_t b,int64_t l, int64_t r, int64_t m, int64_t t){
  return (t*m) >= (a*(r-l+1) + b*((r)*(r-1) -(l-1)*(l-2))/2 );
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int64_t a, b, n;
  int64_t l, m, t;
  cin >> a >> b >> n;
  for (int i = 0; i < n; i++) {
    cin >> l >>t >> m;
    int64_t low = l;
    int64_t high = (t-a)/b+1;
    int64_t mid;

    // Not even enough time to eat the L Karaf
    if(high < low){
      std::cout << -1 << std::endl;
      continue;
    }
    else {
      while(high > low){
        mid = low + (high-low+1)/2;
        if (canFinished(a, b, l, mid, m, t)){
          low = mid;
        }
        else {
          high = mid-1;
        }
      }
      if (canFinished(a, b, l, low, m, t)) { std::cout << low << std::endl;}
      else std::cout << -1 << std::endl;
    }
  }


  return 0;
}
