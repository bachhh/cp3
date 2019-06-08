#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int tc; cin >> tc;
  for(int cn = 1; cn <= tc; ++cn ){
    int r, c, m ,n;
    cin >> r >> c >> m  >>n;
    map<char, int> dict;
    char temp;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cin >> temp;
        dict[temp]++;
      }
    }

    int mx = 0;
    for (auto p : dict) {
      mx = max(mx, p.second);
    }
    int output = 0;
    for (auto p : dict) {
      if (p.second == mx){
        output += m*p.second;
      }
      else{
        output += n*p.second;
      }
    }

    printf("Case %d: %d\n", cn, output);
  }

  return 0;
}

