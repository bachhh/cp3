#include <bits/stdc++.h>

using namespace std;

/*
 * TODO:
 * ### METHODS:
 * Vec::double angle() : return the angle of vector
 * Vec::scale () constructor from another vector with a scale
 * Point::translate(point)
 */

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

class Line{
  public:
    double a;
    double b;
    double c;
    Line() : a(0), b(0), c(0) {}
    Line(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
    Line(Point p1, Point p2){
      if (fabs(p1.x-p2.x) < EPS){
        a = 1.0;
        b = 0.0;
        c = -p1.x;
      }
      else {
        a = -(p1.y-p2.y)/(p1.x - p2.x);
        b = 1.0;
        c = -(a*p1.x)- p1.y;
      }
    }
    bool isParallel(Line l){
      return fabs(this->a - l.a) < EPS && fabs(this->b - l.b) < EPS;
    }
    bool isSame(Line l){
      return this->isParallel(l) && fabs(this->c - l.c) < EPS;
    }
    bool isIntesect(Line l, Point &p){
      if(this->isParallel(l)) return false;
      p.x = (l.b * this->c - this->b*l.c)/(l.a*this->b + l.b*this->a);
      if (fabs(this->b) > EPS)  p.y = -(this->a*p.x + this->c);
      else                      p.y = -(l.a*p.x + l.c);
      return true;
    }
};

class Vec{
  double x;
  double y;
  Vec(): x(0), y(0) {}
  Vec(double _x, double _y) : x(_x), y(_y) {}
  Vec(Point p1, Point p2){
    x = p2.x - p1.x;
    y = p2.y - p1.y;
  }
  Vec(Point p) : x(p.x), y(p.y) {}
  // Cross product of vectors
  double operator * (Vec v){
    return (this->x*v.x + this->y*v.y);
  }
  double magsq(void){
    return (x*x+y*y);
  }
  int isClockwise(Vec v){
    if((*this)*v > EPS ){
      return 1;
    }
    else if ( (*this)*v < -EPS){
      return -1;
    }
    // Vectors points are collinear
    return 0;
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

    bool isIntersect(Line l2){
      int signa = a.x*l2.a + a.y*l2.b +l2.c;
      int signb = b.x*l2.b + b.y*l2.b +l2.c;
      return (signa/signa != signb/signb);
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

  return 0;
}

