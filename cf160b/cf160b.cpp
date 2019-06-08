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
  n*= 2;
  string s;
  cin >> s;
  string s1 = s.substr(0, n/2);
  string s2 = s.substr(n/2, n/2);

  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  if (s1[0] > s2[0]){

    for (int i = 1; i < n/2; ++i) {
      if (s1[i] <= s2[i]){
        std::cout << "NO" << std::endl;
        return 0;
      }
    }
    std::cout << "YES" << std::endl;

  }
  else if(s1[0] < s2[0]){
    for (int i = 0; i < n/2; ++i) {
      if(s1[i] >= s2[i]){
        std::cout << "NO" << std::endl;
        return 0;
      }
    }
    std::cout << "YES" << std::endl;
  }
  else {
    std::cout << "NO" << std::endl;
  }

  return 0;
}

