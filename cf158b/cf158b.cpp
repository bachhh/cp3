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
  int s[100000];
  int cars = 0;

  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  sort(s, s+n,
      [ ] (int a, int b){
        return a > b;
  });

  int l= 0;
  int r= n-1;

  while(s[l] == 4){
    cars++;
    l++;
  }

  while(l < r){
    if(s[l] + s[r] < 4){
      s[l] += s[r];
      r--;
    }
    else if(s[l] + s[r] == 4){
      cars++;
      l++;
      r--;
    }
    else if(s[l] + s[r] > 4){
      cars++;
      l++;
    }
  }
  if(l == r) cars++;

  std::cout << cars  << std::endl;
  return 0;
}

