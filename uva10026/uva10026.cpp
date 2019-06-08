#include <iostream>
#include <assert.h>
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

void swap(int* a, int *b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  int tc, n, a, b;
  vector<tuple<int, int,int>> v;
  cin >> tc;
  for(int i =0; i < tc; ++i){
    v.clear();
    cin >> n;
    for(int i = 1; i <= n; i++){
      cin >> a >> b;
      v.push_back(make_tuple(i, a, b));
    }

    // For any 2 jobs a, b, if the cost of delaying a by the time taken to do b
    // is greater than the otherway, then we prioritize a before b
    sort(v.begin(), v.end(), [](tuple<int, int, int> a, tuple<int, int, int> b){

            // Sort lexicographically
            if(get<2>(a) * get<1>(b) == get<1>(a) * get<2>(b)){
              return get<0>(a) < get<0>(b);
            }
            else {
              return get<2>(a) * get<1>(b) > get<1>(a) * get<2>(b);
            }
         });

    for(int i = 0; i < v.size(); ++i){
      cout << get<0>(v[i]);
      if ( i < v.size() - 1 ) cout << " ";
    }
    cout << endl;
    if ( i < tc - 1) cout << endl;
  }
  return 0;
}

