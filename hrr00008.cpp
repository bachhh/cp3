#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  if (s[s.size()-2] == 'P'){
    if (s[0] != '1' || s[1] != '2'){
      s[1] += 2;
      if (s[1] > '9'){
        s[0] += 2;
        s[1] -= 10;
      }
      else {
        s[0] += 1;
      }
    }
  }

  if (s[s.size()-2] == 'A'){
    if (s[0] == '1' && s[1] == '2'){
      s[0] = '0';
      s[1] = '0';
    }
  }

  cout << s.substr(0, s.size()-2 ) << endl;

  return 0;
}

