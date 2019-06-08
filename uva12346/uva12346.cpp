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
#define LOOP(n) for (int z = 0; z < n; ++z)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )


int matrix[1025][1025];
//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  vector<int> cost;
  vector<int> rate;
  int n, temp, tc, vol, t, total_cost, total_flow;
  int min_cost;
  cin >> n;
  LOOP(n){
    cin >> temp;
    rate.push_back(temp);
    cin >> temp;
    cost.push_back(temp);
  }
  cin >> tc;
  LOOP(tc){
    min_cost = INF;
    cin >> vol >> t;

    for(int config = 0; config < (1<< n); ++config){
      total_cost = 0;
      total_flow = 0;
      for(int gate = 0; gate < n; ++gate){
        // If gate is open in this configuration
        if (config & (1 << gate)){
          total_flow += rate[gate];
          total_cost += cost[gate];
        }
      }
      if(total_flow * t >= vol){
        min_cost = MIN(min_cost, total_cost);
      }
    }
    cout << "Case " << z+1 << ": ";
    if (min_cost == INF) cout << "IMPOSSIBLE" << endl;
    else cout << min_cost << endl;
  }
}


