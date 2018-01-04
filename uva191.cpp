#include <bits/stdc++.h>

using namespace std;


#define EPS 1e-9
#define PI 3.141592653589793
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )
#define LIMIT 100

double maxf(double a, double b){
  if (a-b > EPS) return a;
  return b;
}

double minf(double a, double b){
  if (a-b > EPS) return b;
  return a;
}


double DEG_TO_RAD(double a){
  return (a * PI)/180.00;
}

class Point{
  public:
    double x;
    double y;
    Point() :  x(0), y(0) {}
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
      return Point(p.x*cos(rad) - p.y*sin(rad), p.x*sin(rad) + p.y*cos(rad));
    }
};

class Segment{
  public:
    Point a;
    Point b;
    Segment(void) : a(), b(){}
    Segment(Point _a, Point _b) : a(_a), b(_b) {}
    Segment(double x1,double y1,double x2,double y2 ) : a(x1, y1), b(x2, y2) {}

    // Given three colinear points p, q, r, the function checks if
    // point q lies on line segment 'pr'
    bool onSegment(Point p, Point q, Point r) {
        if (q.x - maxf(p.x, r.x) <= EPS && q.x - minf(p.x, r.x) >= EPS &&
                    q.y - maxf(p.y, r.y) <= EPS && q.y - minf(p.y, r.y) >= EPS)
           return true;
        return false;
    }

    int orientation(Point p, Point q, Point r) {
        double val = (q.y - p.y) * (r.x - q.x) -
                  (q.x - p.x) * (r.y - q.y);
        if ( fabs(val) < EPS ) return 0;  // colinear
        else if (val > EPS) return 1;
        else return -1;
    }

    // The main function that returns true if line segment 'p1q1'
    // and 'p2q2' intersect.
    bool isIntersect(Segment s2) {
        return isIntersect(this->a, this->b, s2.a, s2.b );
    }
    bool isIntersect(Point p1, Point q1, Point p2, Point q2 ){
        int o1 = orientation(p1, q1, p2);
        int o2 = orientation(p1, q1, q2);
        int o3 = orientation(p2, q2, p1);
        int o4 = orientation(p2, q2, q1);
        if (o1 != o2 && o3 != o4)
            return true;
        if (o1 == 0 && onSegment(p1, p2, q1)) return true;
        if (o2 == 0 && onSegment(p1, q2, q1)) return true;
        if (o3 == 0 && onSegment(p2, p1, q2)) return true;
        if (o4 == 0 && onSegment(p2, q1, q2)) return true;
        return false; // Doesn't fall in any of the above cases
    }
};

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  double lxs, lys;
  double lxe, lye;
  double xl, yt, xr, yb;

  int tc; cin >> tc;
  while(tc--){
    cin >> lxs >> lys >> lxe >> lye;
    cin >> xl >> yt >> xr >> yb;
    Segment l(lxs, lys, lxe, lye);
    Point r1(xl, yt);
    Point r2(xr, yt);
    Point r3(xr, yb);
    Point r4(xl, yb);
  }
  return 0;
}

