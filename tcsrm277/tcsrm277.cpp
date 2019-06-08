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
#define FLOAT_PRECISION 1e-10

void swap(int* a, int *b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}


// Compute the index for any given n
int32 nthElement(vector<int> lowerBound, vector<int> upperBound,int n){
  // Loop over elements of lowerBound


  int32 low = 2000000001, high = 0, mid;
  for(int i =0; i < lowerBound.size(); ++i){
    low = MIN(low, lowerBound[i]); high= MAX(high, upperBound[i]);
  }

  int32 high_rank, low_rank;
  while(low <= high){

    mid = low + (high - low)/2;
    high_rank = low_rank = 0;

    for(int i =0; i< lowerBound.size(); ++i){
      if (mid > upperBound[i]){
        low_rank += upperBound[i] - lowerBound[i] + 1;
        high_rank += upperBound[i] - lowerBound[i] + 1;
      }
      else if (mid <= upperBound[i] && mid >= lowerBound[i]){
        low_rank += mid - lowerBound[i];
        high_rank += mid - lowerBound[i]+1 ;
      }
    }
    high_rank--;

    if (n <= high_rank && n >= low_rank){
      break;
    }
    else if ( high_rank < n){
      low = mid+1;
    }
    else if ( n < low_rank){
      high = mid-1;
    }
  }
  return mid;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);

  vector<int> lowerBound = {-1, 1, 1};
  vector<int> upperBound = { 5, 3, 4};
  for(int i =0; i < 14; i++)
  cout << nthElement(lowerBound, upperBound, i) << endl;
  return 0;
}

