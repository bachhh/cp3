#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  map<char, int> _s1;
  map<char, int> _s2;

  for (char c : s1) {
    if(c == ' ') continue;
    _s1[c]++;
  }

  for (char c : s2) {
    if(c == ' ') continue;
    _s2[c]++;
  }

  for (auto p : _s2) {
    if(_s1[p.first] < p.second){
      std::cout << "NO" << std::endl;
      return 0;
    }
  }

  std::cout << "YES" << std::endl;

  return 0;
}

