#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
#define EPS 1e-9
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int xa, ya, xb, yb;
  cin >> xa >> ya >> xb >> yb;
  if(xa > xb){
    swap(xa, xb);
  }
  if(ya > yb){
    swap(ya, yb);
  }
  vector<ii> v;
  int vx[10000];
  int vy[10000];

  int end = 0;
  for (int i = xa; i <= xb; ++i) {
    vx[end] = i;
    vy[end] = ya;
    end++;
  }
  for (int i = ya+1; i <= yb; ++i) {
    vx[end] = xa;
    vy[end] = i;
    end++;
  }

  for (int i = xa+1; i <= xb; ++i) {
    vx[end] = i;
    vy[end] = yb;
    end++;
  }

  for (int i = ya+1; i < yb; ++i) {
    vx[end] = xb;
    vy[end] = i;
    end++;
  }


  int n; cin >> n;

  int x[1000];
  int y[1000];
  int r[1000];

  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i] >> r[i];
  }

  int output = 0;
  for (int j = 0; j < end; j++) {
    int heated = false;
    double _x = vx[j],  _y = vy[j];
    for (int i = 0; i < n; ++i) {
      if ( (_x - x[i])*(_x-x[i]) + (_y - y[i])*(_y-y[i]) < (r[i] + EPS)*(r[i] + EPS)){
        heated = true;
        break;
      }
    }
    if (!heated){
      output++;
    }
  }
  std::cout << output << std::endl;

  return 0;
}

