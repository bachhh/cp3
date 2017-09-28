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

int main(){
  // Test IO
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int matrix[n][n];
  for (int i =0; i<n; ++i){
    for (int j =0; j<n; ++j){
      if (i == 0 || j == 0){
        matrix[i][j] = 1;
      }
      else{matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];}
    }
  }

  cout << matrix[n-1][n-1] << endl;

  return 0;
}
