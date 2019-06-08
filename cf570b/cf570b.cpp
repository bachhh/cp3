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

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int32_t n, m;
  cin >> n >> m;


  if( n == 1){
    std::cout << 1 << std::endl;
  }
  else if ( m <= n/2){
    std::cout << m+1 << std::endl;
  }
  else if (m > n/2){
    std::cout << m-1 << std::endl;
  }

  return 0;
}

