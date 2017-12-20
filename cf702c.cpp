#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define VISITED 1
#define UNVISITED -1

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define LIMIT 100001

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);


  int32_t city[LIMIT];
  int32_t tower[LIMIT];

  int n, m; cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> city[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> tower[i];
  }

  int64_t r = 0;
  int64_t closest_dist;
  int64_t lower, upper;
  // For each city find the coordinate of the closest tower
  for (int i = 0; i < n; i++) {
    int32_t* lower = lower_bound(tower, tower+m, city[i]);
    int32_t* upper = upper_bound(tower, tower+m, city[i]);
    // Default case: tower is right on city
    closest_dist = 0;
    // None right on the city
    if (lower - tower == m || *lower > city[i]) {
      //If all tower is greater than the city
      if (lower == tower){
        closest_dist = abs(*upper-city[i]);
      }
      // If all tower is smaller than the city
      else if ( lower-tower == m  && upper - tower == m ) {
        lower--;
        closest_dist = abs(*lower - city[i]);
      }
      // There are towers on both side
      else {
        lower--;
        closest_dist = MIN(abs(*lower-city[i]), abs(*upper-city[i]));
      }
    }
    r = MAX(closest_dist, r);
  }

  std::cout << r << std::endl;

  return 0;

}

