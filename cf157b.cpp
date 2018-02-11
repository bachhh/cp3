#include <bits/stdc++.h>

using namespace std;

#define PI acos(-1)
#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int r[100];
  for (int i = 0; i < n; ++i) {
    cin >> r[i];
  }

  sort(r, r+n,
      [ ] (int a, int b){
        return a>b;
      }
  );

  double output = 0;
  bool red = true;
  for (int i = 0; i < n; ++i) {
    if (red){
      output += PI*r[i]*r[i];
    }
    else {
      output -= PI*r[i]*r[i];
    }
    red = !red;
  }

  printf("%.12lf\n", output);


  return 0;
}

