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
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

void swap(int* a, int *b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  int k;
  uint64 y;
  while(cin >> k && k != 0){
    /*
     * 1/x = 1/k - 1/y;
     * x = y*k/(y-k)
     *
     */
    int count = 0;
    vector<uint64> ys;
    for (y = k+1; y <= 2*k; ++y){
      if ( (y*k) % (y-k) == 0){
        count++;
        ys.push_back(y);
      }
    }
    printf("%d\n", count);
    for(int i =0; i < ys.size(); ++i){
      uint64 x = (ys[i]*k)/(ys[i]-k);
      printf("1/%d = 1/%llu + 1/%llu\n", k, x ,ys[i]);
    }
  }

  return 0;
}

