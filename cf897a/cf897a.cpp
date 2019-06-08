#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  string s;
  int l, r;
  char c1, c2;
  cin >> n >> m;
  cin >> s;
  for (int j = 0; j < m; j++) {
    cin >> l >> r >> c1 >> c2;
    for (int i = l-1; i < r; i++) {
      if (s[i] == c1){
        s[i] = c2;
      }
    }
  }
  std::cout << s << std::endl;



  return 0;
}

