#include <bits/stdc++.h>

using namespace std;

#define LIMIT 200001

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k, a;
  cin >> n >> k >> a;

  int m; cin >>m;
  vector<int> x(m);

  for (int i = 0; i < m; i++) {
    cin >> x[i];
  }

  int output = -1;
  int low = 0, high = m, mid;
  while(low< high){

    mid = low + (high-low)/2;
    int ship = 0;
    // Calculate the number of placable ship based on segments
    vector<bool> shot(n, false);
    for (int i = 0; i <= mid; i++) { shot[x[i]] = true; }
    int len = 0;
    for (int i = 1; i <= n; i++) {
      if (shot[i]){ ship += (len+1)/(a+1); len = 0; }
      else{ ++len; }
    }
    ship += (len+1)/(a+1);

    if (ship >= k){
      low = mid+1;
    }
    else{
      output = mid;
      high = mid;
    }
  }

  int ship = 0;
  // Calculate the number of placable ship based on segments
  vector<bool> shot(n, false);
  for (int i = 0; i <= mid; i++) { shot[x[i]] = true; }
  int len = 0;
  for (int i = 1; i <= n; i++) {
    if (shot[i]){ ship += (len+1)/(a+1); len = 0; }
    else{ ++len; }
  }
  ship += (len+1)/(a+1);

  if (ship >= k){
    std::cout << -1 << std::endl;
  }
  else {
    std::cout << low+1 << std::endl;
  }

  return 0;
}

