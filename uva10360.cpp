#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <list>
#include <unordered_map>
#include <sstream>
#include <stack>
#include <queue>
#include <deque>
#include <iterator>
#include <bitset>
#include <algorithm>
#include <tuple>
#include <functional>
#include <ctime>

using namespace std;

typedef long int int32;
typedef long long int int64;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;
const double pi = acos(-1.0);

#define PI 3.1415926535897932384626433832795
#define INF (int)1e9
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define LOOP(n) for (int i = 0; i < n; ++i)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )



int matrix[1025][1025];
//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  int tc; cin >> tc;
  int d,n, x, y, p, max_kill, kill, bomb_x, bomb_y;
  while(tc--){
    for(int i =0; i < 1025;++i){
      memset(matrix[i], 0, sizeof(int)*1025);
    }
    cin >> d >> n;
    while(n--){
      cin >> x >> y >> p;
      for (int a = MAX(x-d, 0); a <= MIN(1024, x+d); ++a){
        for (int b = MAX(y-d, 0); b <= MIN(1024, y+d); ++b){
          matrix[a][b] += p;
        }
      }
    }
    max_kill = 0, bomb_x = 0; bomb_y = 0;
    for(int a = 0; a < 1025; ++a){
      for(int b =0; b < 1025; ++b){
        if (matrix[a][b] > max_kill ){
          bomb_x = a;
          bomb_y = b;
          max_kill = matrix[a][b];
        }
      }
    }
    cout << bomb_x << " " << bomb_y << " " << max_kill << endl;
  }
  return 0;
}

