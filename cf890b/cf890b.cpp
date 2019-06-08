#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> a(200004, 0);
  vector<int> last(200004, 0);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = n; i > 0; --i) {
    if (last[a[i]] == 0){
      last[a[i]] = i;
    }
  }
  int cafes, t = INT_MAX;
  for (int i = 0; i < 200001; i++) {
    if (last[i] && last[i] < t){
      cafes = i;
      t= last[i];
    }
  }
  std::cout << cafes << std::endl;



  return 0;
}

