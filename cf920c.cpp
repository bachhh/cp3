#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int64_t n;
  cin >> n;

  vector<int64_t> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  string s;
  cin >> s;

  vector<int64_t> suff(n);

  suff[n-1] = 0;

  for (int i = s.size()-1; i >= 0; --i) {
      suff[i] = suff[i+1];
    if (s[i] == '0'){
      suff[i]++;
    }
  }

  for (int i = n-1; i>= 0; --i) {
    if (a[i]-1 >= i){
      continue;
    }
    else {
      int zeros = suff[a[i]-1] - suff[i];
      if (zeros>0){
        std::cout << "NO" << std::endl;
        return 0;
      }
    }
  }


  std::cout << "YES" << std::endl;

  return 0;
}

