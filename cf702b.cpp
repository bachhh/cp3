#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define VISITED 1
#define UNVISITED -1

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )
#define DEBUG(x) cerr << #x << " is " << x << endl;
#define LIMIT 100001


// Rolling my own lower_bound and upper_bound
int lowerBound(int64_t *v, int key, int to, int from = 0 ){
  // ### return the index of the largest value no less than key
  int low = from, high = to, mid;
  while(high > low){
    mid = (high-low)/2 + low;
    if (v[mid] < key ){
      low = mid+1;
    }
    else if (v[mid] >= key){
      high = mid;
    }
  }
  if (v[low] == key) return low;
  else return -1;
}

int upperBound(int64_t *v, int key, int to, int from = 0){
  // ### return the index of the smallest value which is greater than key
  int low = from, high = to, mid;
  while(high > low){
    mid = (high-low)/2 + low;
    if (v[mid] <= key ){
      low = mid+1;
    }
    else if (v[mid] > key){
      high = mid;
    }
  }

  // Return end of array + 1 if no value is greater than key
  if (v[low] <= key) return to+1;
  return low;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin  >> n;

  /*  @@@@@@ stupid solution
  map<uint64_t, uint64_t> m;
  uint64_t temp, p_n = 0;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    m[temp]++;
  }

  uint64_t powof2;
  for (auto p : m) {
    powof2 = 2;
    while(powof2 != 0){
      if( powof2 > p.first &&
          powof2 - p.first == p.first&&
          p.second > 1){
        p_n += ( p.second * (p.second-1) );
      }
      else if( powof2 > p.first &&
          m.find(powof2-p.first) != m.end() &&
          powof2 - p.first != p.first){
        p_n += p.second * m[powof2-p.first];
      }

      powof2 = powof2 << 1;
    }
  }
  */
  int64_t powerOf2[32];
  int64_t v[LIMIT];

  for (int i = 0; i <= 31; i++) {
    powerOf2[i] = ((int64_t)1) << (i+1);
  }

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v, v+n);
  int64_t answer = 0;
  int64_t key;
  for (int i = 0; i < n-1; i++) {
    for (int sum = 0; sum < 31; ++sum) {
      key = powerOf2[sum] - v[i];
      int lower = lowerBound(v, key, n-1, i+1 );
      int upper = upperBound(v, key, n-1, i+1 );
      if (lower > i ) answer += upper - lower;
    }
  }
  std::cout << answer << std::endl;
  return 0;

}

