#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

double vp, vd, t, f, c;

double meet(double x1, double x2){
  return ((x2-x1)/(vd-vp))*vp+x2;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> vp >> vd >> t >> f >> c;
  double princess = vp * t;
  double dragon = 0;
  if(vp >= vd){
    std::cout << 0 << std::endl;
    return 0;
  }

  int counter = 0;
  while(princess < c){
    princess = meet(dragon, princess);
    if (princess < c){
      counter++;
      double t = princess/vd + f;
      princess += vp*t;
      dragon = 0;
    }
    else {
      break;
    }
  }
  std::cout << counter << std::endl;

  return 0;
}

