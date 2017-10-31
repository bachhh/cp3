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
  int a1, a2, a3, b1, b2, b3, n;
  cin >> a1>>a2>>a3>>b1>>b2>>b3>>n;
  int a = a1+a2+a3;
  int b = b1+b2+b3;
  if((a/5 + (a%5>0) + b/10+ (b%10>0)) > n) cout <<"NO" << endl;

  else cout << "YES" << endl;
}


