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
  int x1, y1, x2, y2, x3, y3, x4, y4;
  cin >> x1 >> y1 >> x2 >> y2;

  if (abs(x1-x2) == abs(y1-y2)){
    printf("%d %d %d %d\n", x1, y2, x2, y1);
    return;
  }
  else if ( /*Parallel*/ (x1 == x2 || y1 == y2 )){
    // x3 is the reflection of x1
    x3 = (x1==x2)?((x1>0)?(x1-abs(y2-y1)):(x1+abs(y2-y1))):(x1);
    // x4 is the reflection of x1
    x4 = (x1==x2)?((x2>0)?(x2-abs(y2-y1)):(x2+abs(y2-y1))):(x2);
    // y3 is the reflection of y1
    y3 = (y1==y2)?((y1>0)?(y1-abs(x1-x2)):(y1+abs(x1-x2))):(y1);
    // y4 is the reflection of y2
    y4 = (y1==y2)?((y2>0)?(y2-abs(x1-x2)):(y2+abs(x1-x2))):(y2);
    if( abs(x3) < 1000 || abs(x4) < 1000 || abs(y3) < 1000 || abs(y4) < 1000){
      printf("%d %d %d %d\n", x3, y3, x4, y4);
      return;
  }
  printf("%d\n", -1);

  return 0;
}


