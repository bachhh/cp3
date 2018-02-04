#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
int n, d;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> d;

  int ma = 0;
  int consec = 0;
  for (int i = 0; i < d; ++i) {
    string s; cin >> s;
    if (s != string(n, '1')){
      consec++;
      ma = max(ma, consec);
    }
    else {
      consec = 0;
    }
  }
  std::cout << ma << std::endl;

  return 0;
}

