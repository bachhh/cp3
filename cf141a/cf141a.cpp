#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string a, b , s;
  cin >> a >> b >> s;
  int counter[26] = {0};
  for (char c : a) {
    counter[c-'A']++;
  }
  for (char c : b) {
    counter[c-'A']++;
  }

  int counter2[26] = {0};
  for (char c : s) {
    counter2[c-'A']++;
  }
  for (int i = 0; i < 26; ++i) {
    if (counter[i] != counter2[i]){
      std::cout << "NO" << std::endl;
      return 0;
    }
  }
  std::cout << "YES" << std::endl;

  return 0;
}

