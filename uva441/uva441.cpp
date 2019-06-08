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

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  int k;
  int a[1000];
  while( cin >> k && k > 0){
    for (int i = 0; i < k; ++i) {
      cin >> a[i];
    }
    sort(a, a+k);
    for (int i = 0; i < k; ++i) {
      for (int j = i+1; j < k; ++j) {
        for (int n = j+1; n < k; ++n) {
          for (int ii = n+1; ii < k; ++ii) {
            for (int jj = ii+1; jj < k; ++jj) {
              for (int nn = jj+1; nn < k; ++nn) {
                printf("%d %d %d %d %d %d \n",
                    a[i], a[j], a[n], a[ii], a[jj], a[nn]);
              }
            }
          }
        }
      }
    }
    printf("\n");

  }

  return 0;
}
