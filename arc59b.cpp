#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  for (int i = 0; i < s.size()-1; ++i) {
    if (s[i] == s[i+1]){
      printf("%d %d\n", i+1, i+2);
      return 0;
    }

    if ( i<s.size()-2 && s[i] == s[i+2] ){
      printf("%d %d\n", i+1, i+3);
      return 0;
    }
  }

  printf("-1 -1\n");

  return 0;
}

