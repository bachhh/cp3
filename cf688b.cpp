#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  string output = s;reverse(s.begin(), s.end());
  output += s;
  std::cout << output << std::endl;

  return 0;
}

