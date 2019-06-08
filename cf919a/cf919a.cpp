#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  int m; cin >> n >> m;

  double a, b;
  double minP = 1000000;

  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (a/b < minP){
      minP = a/b;
    }
  }
  printf("%.12f\n", m*minP);

  return 0;
}

