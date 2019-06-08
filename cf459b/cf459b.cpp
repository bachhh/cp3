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
  int64 n, temp;
  int v[200000];
  cin >> n;
  int64 min = INF, max =0, min_c =1, max_c =0, d, w;
  for( int i = 0; i < n; ++i){
    cin >> temp;
    if(temp<min){
      min_c =1;
      min = temp;
    }
    else if (temp == min) {
      min_c++;
    }

    if(temp>max){
      max_c = 1;
      max = temp;
    }
    else if (temp == max){
      max_c++;
    }
  }

  d = max - min;
  if (max_c + min_c > n){
    w = n*(n-1)/2;
  }
  else {
    w = max_c*min_c;
  }

  printf("%lld %lld\n", d ,w);


  return 0;
}

