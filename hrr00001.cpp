#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a[4] = {0};
  int b[4] = {0};

  for (int i = 0; i < 3; ++i) {
    cin>> a[i];
  }
  for (int i = 0; i < 3; ++i) {
    cin>> b[i];
  }

  for (int i = 0; i < 3; ++i) {
    a[3] += a[i]>b[i];
    b[3] += b[i]>a[i];
  }
  printf("%d %d\n", a[3], b[3]);

  return 0;
}

