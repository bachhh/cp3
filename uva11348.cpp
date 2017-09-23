#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <cmath>
#include <string>
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

using namespace std;

typedef long int int32;
typedef long long int int64;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;

const double pi = acos(-1.0);


#define PI 3.1415926535897932384626433832795
#define INF (int)1e9
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

int main(){

  int tc, n, s, temp;
  cin >> tc;
  map<int, int> s_o;
  int o_c[51];

  for(int j = 1; j <= tc; ++j){
    s_o.clear();
    fill(o_c, o_c + 51, 0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
      cin >> s;
      while(s--){
        cin >> temp;
        // If copies of stamps owned by different owner
        if(s_o.find(temp) != s_o.end() && s_o.at(temp) != i ){
          s_o[temp] = 0;
        }
        // If copies of stamps owned by the same owner
        else{
          s_o[temp] = i;
        }
      }
    }
    double total = 0;
    for(map<int, int>::iterator it = s_o.begin(); it != s_o.end(); ++it){
      if (it->second != 0){
        o_c[it->second]++;
        total++;
      }
    }

    cout << "Case " << j << ":";
    for (int i = 1; i <= n; ++i){
      printf(" %.6lf", double( 100.*(o_c[i] / total)));
      cout << "%";
    }
    cout << endl;

  }
  return 0;
}
