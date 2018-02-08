#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){

  string s;
  cin >> s;
  s += '.';

  int alphabet[26] = {0};
  int consec = 1;

  for (int i = 1; i < s.size(); ++i) {
    if (s[i] != s[i-1] && alphabet[s[i-1]-'a'] < consec ){
      alphabet[s[i-1]-'a'] = consec;
      consec = 1;
    }
    else if (s[i] == s[i-1]){
      consec++;
    }

  }

  int n; cin >> n; int q;

  for (int i = 0; i < n; ++i) {
    cin >> q;
    bool found = false;
    for (int j = 1; (!found) && j <= 26; ++j) {
      if(alphabet[j-1] > 0 && (alphabet[j-1]*j) % q == 0){
        found = true;
      }
    }
    if (!found) std::cout << "No" << std::endl;
    else std::cout << "Yes" << std::endl;
  }
}

