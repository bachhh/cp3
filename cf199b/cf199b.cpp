#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a[4];
  int b[4];

  for (int i = 0; i < 4; ++i) { cin >> a[i]; }
  for (int i = 0; i < 4; ++i) { cin >> b[i]; }
  int d = hypot(a[0] - b[0], a[1] - b[1]);

  return 0;
}

