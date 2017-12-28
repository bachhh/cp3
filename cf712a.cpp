#include <bits/stdc++.h>

using namespace std;

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define LIMIT 100001

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);


  int tc; cin >> tc;

  int64_t a[LIMIT] = {0};
  int64_t b[LIMIT] = {0};

  for (int i = 0; i < tc; i++) {
    cin >> a[i];
  }

  b[tc-1] = a[tc-1];
  for (int i = tc-2; i >= 0; --i){
    b[i] = a[i] + a[i+1];
  }

  for (int i = 0; i < tc; i++) {
    cout << b[i]  << " \n"[i==tc-1];
  }

  return 0;
}

