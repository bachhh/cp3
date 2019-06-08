#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int tc; cin >> tc;
  while(tc--){

    int n, k;
    cin >> n >> k;

    int x[2001] = {0};

    memset(x, 0, sizeof(int)*2001);

    for (int i = 0; i < k; i++) {
      cin >> x[i];
    }

    /*
    for (int i = 0; i < k; i++) {
      cout << x[i] << " \n"[i==k-1];
    }
    */

    int max_dist = 1;
    for (int i = 1; i <= n; i++) {

      int r = upper_bound(x, x+k, i) - x;
      int l = lower_bound(x, x+k, i) - x;

      //std::cout << i << "|" <<  l << "|" << r << std::endl;
      int ldist = 100000;
      int rdist = 100000;

      if (r < k){
        rdist = abs(x[r] - i)+1;
      }

      if(l == k){
        l--;
        ldist = abs(x[l] - i)+1;
      }
      else if(x[l] == i){
        ldist = 1;
      }
      else if(l > 0 && x[l] > i){
        l--;
        ldist = abs(x[l] - i) + 1;
      }

      max_dist = max(max_dist, min(ldist, rdist));

    }
    std::cout << max_dist << std::endl;


  }


  return 0;
}

