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
  int n, k;
  double v[10001];

  double avg = 0, source, sink, min = 1001;
  cin >> n >> k;
  for(int i =0; i < n; ++i){
    cin >> v[i];
    avg += v[i];
    min = MIN(min, v[i]);
  }
  avg /= n;

  // The average
  double low = min, high = avg, mid;
  while (high - low > FLOAT_PRECISION){
    mid = low + (high - low)/2;
    source = sink = 0;
    for(int i = 0; i < n; ++i){
      if (v[i] - mid > FLOAT_PRECISION){
        source += v[i] - mid;
      }
      else if(v[i] - mid < FLOAT_PRECISION){
        sink += mid - v[i];
      }
    }
    // Source transfer to sink must be equal to percentage
    source = source*(100-k)/100;
    if( source - sink < FLOAT_PRECISION || sink - 0 < FLOAT_PRECISION){
      high = mid;
    }
    else if (source - sink > FLOAT_PRECISION || source - 0 < FLOAT_PRECISION){
      low= mid;
    }
    else {
      break;
    }
  }
  printf("%6f\n", low);

  return 0;
}

