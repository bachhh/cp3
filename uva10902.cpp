#include <bits/stdc++.h>

using namespace std;

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define EPS 1e-9
#define PI 3.141592653589793
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



// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r) {
    if (q.x - max(p.x, r.x) <= EPS && q.x - min(p.x, r.x) >= EPS &&
                q.y - max(p.y, r.y) <= EPS && q.y - min(p.y, r.y) >= EPS)
       return true;
    return false;
}

int orientation(Point p, Point q, Point r) {
    double val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
    if (abs(val) < EPS ) return 0;  // colinear
    return (val > EPS ) ? 1: -1; // clock or counterclock wise
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool isIntersect(Point p1, Point q1, Point p2, Point q2) {
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    // General case
    if (o1 != o2 && o3 != o4)
        return true;
    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
    return false; // Doesn't fall in any of the above cases
}


typedef long int int32; typedef long long int int64;
typedef unsigned long int uint32; typedef unsigned long long int uint64;
typedef pair<int, int> ii; typedef vector<ii> vii; typedef vector<int> vi;
typedef vector<vi> vvi;


//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  double x1, y1, x2, y2;

  while(cin >> n && n != 0 ){
    vector<pair<Point, Point>> s;
    vector<int> output;

    for (int i = 0; i < n; i++) {
      cin >> x1 >> y1 >> x2 >> y2;
      s.push_back(make_pair(Point(x1, y1), Point(x2, y2)));
    }

    for (int i = s.size()-1; i >= 0; --i) {
      Point p1 = s[i].first;
      Point p2 = s[i].second;

      output.push_back(i+1);
      for (int j = i+1; j < n; j++) {
        if(isIntersect(p1, p2, s[j].first, s[j].second)){
          output.pop_back();
          break;
        }
      }
    }


    printf("Top sticks:");
    // Reverse the order
    for (int i = output.size()-1; i >= 0 ; --i) {
      if (i > 0)
        printf(" %d,", output[i]);
      else
        printf(" %d.\n", output[i]);
    }

  }

  return 0;
}

