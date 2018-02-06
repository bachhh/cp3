#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  int neg = 0, pos = 0, zero = 0;
  int a;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    if ( a < 0){
      neg++;
    }
    else if (a > 0){
      pos++;
    }
    else {
      zero++;
    }
  }

  printf("%.12f\n", (double)pos/n);
  printf("%.12f\n", (double)neg/n);
  printf("%.12f\n", (double)zero/n);

  return 0;
}

