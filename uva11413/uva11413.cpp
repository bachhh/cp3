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
  int n, m, low, high, mid, container, cap, max = 0;
  int c[1000];
  int64 sum;

  while(cin >> n >> m){
    max = sum = 0;
    for(int i = 0; i < n; ++i){
      cin >> c[i];
      sum += c[i];
      max = MAX(max, c[i]);
    }

    low = max, high = sum;
    while(low < high){
      mid = low + (high - low)/2;
      container = 1;
      cap = 0;
      for(int i =0; i < n; ++i){
        if (cap + c[i] <= mid){
          cap += c[i];
        }
        else {
          container++;
          cap = c[i];
        }
      }
      // More capacity  <-> less container
      // def p(x) :: container <= m
      if (container <= m){
        high = mid;
      }
      else {
        low = mid + 1;
      }
    }
    cout << low << endl;
  }
  return 0;
}

