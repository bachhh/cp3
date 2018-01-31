#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  string s; cin >> s;

  int output = 0;
  for (int i = 0; i < s.size()-1; i++) {
    if (s[i] == 'S'&& s[i+1] == 'F'){
      output++;
    }
    else if(s[i] == 'F' && s[i+1] == 'S') {
      output--;
    }
  }

  if (output > 0) {
    std::cout << "YES" << std::endl;
    return 0;
  }
  std::cout << "NO" << std::endl;
  return 0;
}

