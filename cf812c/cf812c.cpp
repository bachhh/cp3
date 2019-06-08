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

int k = 0;

int comp(const void* a, const void* b) {
  const int64* x =  static_cast<const int64* >(a);
  const int64* y =  static_cast<const int64* >(b);
  int64 a_p = x[0] + x[1] * k;
  int64 b_p = y[0] + y[1] * k;
  if( a_p > b_p ){
    return 1;
  }
  else if (a_p == b_p) {
    return 0;
  }
  else{
    return -1;
  }
}

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  uint64 n, s;
  int64 base[100005][2];
  uint64 sum;
  cin >> n >> s;
  for(int i = 0; i < n; i++){
    cin >> base[i][0];
    base[i][1] = i+1;
  }

  // Binary deduction for the right value of k
  int l = 0, r = n;

  while( l <= r ){
    k = (l + r)/2;
    qsort(base, n, sizeof(*base), comp);
    sum = 0;
    for( int index = 0; index < k; ++index){
      sum += base[index][0] + k*base[index][1] ;
    }

    if (s < sum){
      r = k-1;
    }
    else if ( s > sum){
      l = k+1;
    }
    else {
      break;
    }
  }

  if ( sum == s){
    printf("%d %lld\n", k, sum);
  }
  else if (sum != s){
    sum = 0;
    k = l-1;
    qsort(base, n, sizeof(*base), comp);

    for(int index = 0; index < (l-1); ++index){
      sum += base[index][0] + (l-1) * base[index][1];
    }
    printf("%d %lld\n", l-1, sum);
  }

  return 0;
}

