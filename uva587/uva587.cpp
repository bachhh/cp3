#include <bits/stdc++.h>

using namespace std;

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define EPS 1e-9
#define PI acos(-1)
#define LIMIT 100

double DEG_TO_RAD(double a){
  return (a * PI)/180.00;
}
double sin2(const double a){
  if (fabs(sin(a)) > EPS) return sin(a);
  else return 0;
}

double cos2(const double a){
  if (fabs(cos(a)) > EPS) return cos(a);
  else return 0;
}

class Point{
  public:
    double x;
    double y;
    Point(void) :  x(0), y(0) {}
    Point(int _x, int _y) : x(_x), y(_y) {}
    bool operator < (Point p){
      if (fabs(this->x - p.x) > EPS){
        return this->x < p.x;
      }
      else {
        return this->y < p.y;
      }
    }
    bool operator == (Point p){
      return fabs(this->x - p.x) < EPS && fabs(this->y == p.y) < EPS;
    }
    double dist(){
      return hypot(this->x, this->y);
    }
    double dist(Point p){
      return hypot(this->x - p.x, this->y - p.y);
    }
    Point rotate(Point p, double theta){
      double rad = DEG_TO_RAD(theta);
      return Point(p.x*cos2(rad) - p.y*sin2(rad), p.x*sin2(rad) + p.y*cos2(rad));
    }
};


//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string input;
  int tc = 1;

  map<string, double> dir_to_degree;
  dir_to_degree["E"] = 0.0;
  dir_to_degree["NE"] = 45.0;
  dir_to_degree["N"] = 90.0;
  dir_to_degree["NW"] = 135.0;
  dir_to_degree["W"] = 180.0;
  dir_to_degree["SW"] = 225;
  dir_to_degree["S"] = 270;
  dir_to_degree["SE"] = 315;

  while(cin >> input && input != "END"){
    Point p = Point();
    p.x = p.y = 0;
    string step, dir;
    int from = 0, to = input.find(',', from);
    int mag = 0;
    while(to != string::npos){
      step = input.substr(from, to-from);
      // TODO: parse coordinate string
      int index=0; while(step[index] <='9')index++;
      // Get Magnitude
      mag = stoi(step.substr(0, index));
      // Get direction
      dir = step.substr(index, step.size()-1);
      p.x += mag*cos2(DEG_TO_RAD(dir_to_degree[dir]));
      p.y += mag*sin2(DEG_TO_RAD(dir_to_degree[dir]));
      // END TODO:
      from = to+1;
      to = input.find(',', from);
    }
    to = input.find('.', from);
    step = input.substr(from, to-from);
    int index = 0; while(step[index] <='9')index++;
    // Get Magnitude
    mag = stoi(step.substr(0,index));
    // Get direction
    dir = step.substr(index, step.size()-1);
    // TODO: parse coordinate string
    p.x += mag*cos2(DEG_TO_RAD(dir_to_degree[dir]));
    p.y += mag*sin2(DEG_TO_RAD(dir_to_degree[dir]));
    // END TODO:
    printf("Map #%d\nThe treasure is located at (%.3lf,%.3lf).\nThe distance to the treasure is %3lf.\n\n", tc, p.x, p.y, fabs(hypot(p.x, p.y)));
    tc++;
  }

  return 0;
}

