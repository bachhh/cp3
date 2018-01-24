#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

int n, k;

//  ***** MAIN *****
int main(){

  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  vector<int> v(n, 1);
  v[n-1] = 0;
  vector<int> seq(n);
  v.push_back(0);
  while(k--){
    for (int i = 0 ; i < n; ++i) {
      if (v[i] == n-i-1){
        seq[i] = n;
      }
      else if(v[i] < n-i-1){
        int missing  = n-i-1 - v[i];
        seq[i] = max(n-missing, 1);
        v[i] += v[seq[i]-1];
      }
    }
    for (int i = 0; i < n ; ++i) {
      std::cout << seq[i] << " \n"[i==n-1];
    }
  }


  return 0;
}

