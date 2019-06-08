#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> v(n);
  vector<int> vminus(n);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
    vminus[i] = -v[i];
  }
  vector<int64_t> prefneg(n);
  vector<int64_t> pref(n);

  pref[0] = v[0];
  prefneg[0] = vminus[0];
  for (int i = 1; i < n; i++) {
    pref[i] = v[i]+pref[i-1];
    prefneg[i] = vminus[i] + pref[i-1];
  }


  return 0;
}

