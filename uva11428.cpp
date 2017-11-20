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
  int x, y, temp;
  vector<int32> v;
  bool found;
  while (cin >> temp && temp != 0){
    y = 0;
    found = false;
    while(!found && y <= 100){
      y++;
      x = y;
      while( !found && x*x*x-y*y*y <= temp){
        x++;
        if ( x*x*x - y*y*y == temp){
          found = true;
          printf("%d %d\n", x, y);
        }
      }
    }
    if (!found ) printf("No solution\n");
  }

  return 0;
}

