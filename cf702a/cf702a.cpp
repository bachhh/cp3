#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

typedef long int int32; typedef long long int int64;
typedef unsigned long int uint32; typedef unsigned long long int uint64;
typedef pair<int, int> ii; typedef vector<ii> vii; typedef vector<int> vi;
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
  int n; cin >> n;
  int v[100001];

  // Edge case
  if (n == 1){ std::cout << 1 << std::endl; return 0;}

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int max_size = 0, l = 0,r = 1;
  while(r < n){
    if(l != r && v[r] <= v[r-1] ){
      l = r;
      r = l;
    }
    max_size = MAX(max_size, r-l+1);
    r++;
  }

  std::cout << max_size << std::endl;


  return 0;

}
