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
  int n;

  cin >> n;
  int odd_count = 0;
  int64 min_odd = 1 << 30;
  int64 odd_sum = 0;
  int64 temp;
  int64 sum = 0;

  LOOP(n){
    cin >> temp;
    sum += temp;
    if ( (temp % 2 == 1) && (temp < min_odd)){
      min_odd = temp;
    }

  }

  if (sum % 2 == 1)
    cout << sum - min_odd << endl;
  else
    cout << sum << endl;

  return 0;
}

