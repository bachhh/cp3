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
  int n, temp, m, min_d, d, sum, result;
  int tc =1;
  vector<int> list;
  vector<int>::iterator first, last;
  while(cin >> n && n > 1){
    list.clear();
    while (n--){
      cin >> temp;
      list.push_back(temp);
    }
    std::sort(list.begin(), list.end());
    printf("Case %d:\n",  tc++);
    cin >> m;
    while(m--){
      cin >> sum;
      first = list.begin();
      last = list.end();last--;
      min_d = INF;
      while(true) {
        d = abs((*first + *last) - sum);
        if( d < min_d){
          min_d = d;
          result = *first + *last;
        }
        if(distance(first, last) > 1){
          if(*first+*last < sum){
            first++;
          }
          else if ( *first + *last > sum){
            last--;
          }
          else{
            break;
          }
        }
        else{
          break;
        }

      }
      printf("Closest sum to %d is %d.\n", sum, result);
    }

  }
  return 0;
}

