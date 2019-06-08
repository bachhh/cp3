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
  ios::sync_with_stdio(false);

  int32 n, t, sum = 0;
  cin >> n >> t;

  int v[100005];
  v[0] = 0;
  for(int i = 1; i <= n;++i){
    cin >> v[i];
  }

  for(int i = 1; i <= n; ++i){
    v[i] += v[i-1];
  }


  int max_book = 0;
  int l, r, m;

  for(int i = 1; i <= n; i++){
    l = i, r = n;
    while(l <= r){
      m = (l+r)/2;
      if(v[m] - v[i-1] < t){
        l = m + 1;
      }
      else if(v[m] - v[i-1] > t){
        r = m - 1;
      }
      else if(v[m] - v[i-1] == t){
        break;
      }
    }

    while(v[m] - v[i-1] > t){m--;}
    max_book = MAX(max_book, m-i+1);
  }
  printf("%d\n", max_book);

  return 0;
}

