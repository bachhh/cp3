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

#define LIMIT 1000

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, k;
  cin >> n >> m >> k;

  std::cout << m*(m-1)/2 << std::endl;

  // Standard bubble sort
  for (int i = 1; i < m; ++i) {
    for (int j = i+1; j <=m ; j++) {
      if(k==0) {std::cout << i << " " << j << std::endl; }
      else std::cout << j << " " << i << std::endl;
    }
  }




  return 0;
}

