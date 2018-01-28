#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
#define EPS 1e-9

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  double a, d;
  cin >> a >> d;
  int n; cin >> n;

  for (int i = 1; i <= n; i++) {
    double pos = fmod((i*d),(a*4));
    if (pos <= a){
      printf("%f %f \n", pos, 0.0);
    }
    else if (pos > a && pos < 2*a){
      printf("%f %f \n", a, pos-a);
    }
    else if (pos > 2*a && pos < 3*a){
      printf("%f %f \n", a- (pos - 2*a), a);
    }
    else {
      printf("%f %f \n", 0.0, a-(pos - 4*a));
    }
  }

  return 0;
}

