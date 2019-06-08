#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

int sumdigit(string s){
  int r = 0;
  for (char c : s) {
    r += c-'0';
  }
  return r;
}
//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  vector<string> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int one = 0;
  int two = 0;
  int three = 0;

  for (string s : v) {
    int sud = sumdigit(s);
    switch(sud%3){
      case 1: one++; break;
      case 2: two++; break;
      case 0: three++; break;
      default : return 1;
    }
  }
  std::cout << min(one, two) + three/2 << std::endl;

  return 0;
}

