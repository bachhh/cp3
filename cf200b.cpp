#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int p[100];
  double o = 0;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    o += p[i];
  }
  printf("%.12f\n", o/n);

  return 0;
}

