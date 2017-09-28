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
  int n,temp;
  cin >> n;
  int array[n];
  int count = 0;
  for(int c=0; c<n;c++){
    cin >> temp;
    array[c] = temp;
    if (temp == 0) {count++;}
  }
  int matrix[n][n], max = count;
  matrix[0][n-1] = count;

  for (int column = n-1; column >= 0; column--){
    for(int row = 0; row <= column; row++){
      if(column - row == n-1){
      }
      else if (row == 0) {
        matrix[row][column] = matrix[row][column+1] + ((array[column+1] == 0 ) ? -1 : +1 );
      }
      else{
        matrix[row][column] = matrix[row-1][column] + ((array[row-1] == 0) ? -1: +1);
      }
      max = MAX(max, matrix[row][column]);
    }
  }

  cout << max << endl;


  return 0;
}
