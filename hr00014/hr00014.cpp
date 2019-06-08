#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, d, m;
  int s[10000];
  cin >> n;

  cin >> s[0];

  for (int i = 1; i < n; ++i) {
    cin >> s[i];
    s[i] += s[i-1];
  }
  cin >> d >> m;

  int output = 0;

  for (int i = 0; i < n-m+1; ++i) {
    if (i== 0){
      if (s[i+m-1] == d){
        output++;
      }
    }
    else{
      if (s[i+m-1] - s[i-1] == d){
        output++;
      }
    }
  }

  std::cout << output << std::endl;
  return 0;
}

