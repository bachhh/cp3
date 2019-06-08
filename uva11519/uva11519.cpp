#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
#define PI acos(-1.0)
#define EPS 1e-9

double DEG_TO_RAD(int a){
  return (a * PI)/180.00;
}

int RAD_TO_DEG(double rad){
  if (rad > 0)
    return ceil(rad*180.00)/PI;
  else
    return floor(rad*180.00)/PI;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int tc; cin >> tc;
  while(tc--){
    int n; cin >> n;

    int dir = 0;
    double x1 = 0, y1 = 0;
    double x2 = 0, y2 = 0;
    string command;
    bool flag = false;

    for (int i = 0; i < n; i++) {
      string c; cin >> c;
      string c2;cin >> c2;
      if(c2 == "?"){
        command = c;
        flag = true;
        continue;
      }

      int unit = stoi(c2);
      if (c == "rt"){
        dir += unit;
        if (dir >= 360) dir -= 360;
      }
      else if (c == "lt"){
        dir -= unit;
        if (dir < 0) dir +=360;
      }
      else if (c == "fd"){
        if(!flag){
          x1 += unit*cos(DEG_TO_RAD(dir));
          y1 += unit*sin(DEG_TO_RAD(dir));
        }
        else {
          x2 += unit*cos(DEG_TO_RAD(dir));
          y2 += unit*sin(DEG_TO_RAD(dir));
        }
      }
      else if (c == "bk"){
        if(!flag){
          x1 -= unit*cos(DEG_TO_RAD(dir));
          y1 -= unit*sin(DEG_TO_RAD(dir));
        }
        else {
          x2 -= unit*cos(DEG_TO_RAD(dir));
          y2 -= unit*sin(DEG_TO_RAD(dir));
        }
      }
      printf("%.2lf\t%.2lf\t%.2lf\t%.2lf\n", x1,y1 ,x2 ,y2);

    }

    double dot = x1*x2+y1*y2;
    double det = x1*y2+y1*x2;

    double angle = RAD_TO_DEG(atan2(det, dot));

    if (command == "lt"){
      // left turn == counter clockwise
      if (angle < -EPS){
      }
      else{
      }
    }
    else if (command == "rt"){
      if (angle < -EPS){
      }
      else{
      }
    }
    else if(command == "td" || command == "fd"){
    }

  }
  return 0;
}

