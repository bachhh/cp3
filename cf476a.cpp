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

int check(int move, int step){
}

int matrix[1025][1025];
//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  /*
   * You need minimum foor(n+1)/2 moves to finish n steps of stairs
   * Which can be represented as an array of (n/2)number of 2's
   * The array may or may not end with a 1 ( depends on if n is odd)
   * {2, 2, 2, 2, 2, 1 } n = 11, moves = 6, 2's = n/2
   * We can break down an 2 into 2 one moves which increase moves by 1
   * {2, 2, 2, 2, 1, 1, 1} n = 11, moves = 7
   * Now the number of moves need to be a multiple of m so a multiple of m
   * needs to lies between (n+1)/2 and (n+1)/2 + n/2
   * And the number of moves is the multiple closest to (n+1)/2 inside that range
   *
   */
    // ((n+1)/2-1)/m * m
    // return a multiple of M strictly less than (n+1)/2
    // ((n+1)/2-1)/m * m + m
    // return a multiple of M greater or equal to (n+1)/2
    // ((n+1)/2-1)/m * m + m <= (n+1)/2+n/2
    // check if this multiple is in range
    cout << (((((n+1)/2-1)/m)*m+m<=(n+1)/2+n/2)?(((n+1)/2-1)/m)*m+m:(-1)) << endl;

}


