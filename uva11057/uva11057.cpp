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
#include <climits>

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
#define FLOAT_PRECISION 1e-8

void swap(int* a, int *b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}



//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  int n, m, from, to, i, j;
  int v[100000];

  while (cin >> n){
    for(int i = 0; i < n; ++i){
      cin >> v[i];
    }
    cin >> m;
    sort(v, v+n);
    from = 0, to = n-1;
    while(from < to){
      if (v[from] + v[to] > m ){
        to--;
      }
      else if (v[from] + v[to] < m){
        from++;
      }
      else {
        i = from;
        j = to;
        to--;
      }
    }

    printf("Peter should buy books whose prices are %d and %d.\n\n",v[i], v[j]);
  }

  return 0;
}

