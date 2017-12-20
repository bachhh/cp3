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

#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define LOOP(i, n) for (int i = 0; i < n; ++i)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )
#define DEBUG(x) cerr << #x << " is " << x << endl;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin  >> n;

  map<uint64_t, uint64_t> m;
  uint64_t temp;
  uint64_t p_n = 0;

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
  std::cout << p_n/2 << std::endl;

  return 0;

}

