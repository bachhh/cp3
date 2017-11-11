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

vector<int32> v;

int comp(int index, int value){
  //Return [-1, 0, 1] if interval which is smaller than , equal to, or, greater than the value
  if (v[index] <= value && v[index+1] >= value)
    return 0;
  else if(v[index] > value){
    return 1;
  }
  else if(v[index+1] < value){
    return -1;
  }
  // catch error
  return INF;
}

int binary_search(int value){
  // Return index of the interval which contain the value
  int l = 0;
  int r = (v.size()-1)/2;
  int mid;
  while(l <= r){
    mid = floor((l+r)/2);
    if (comp(mid*2, value) == 0){
      return mid+1;
    }
    else if(comp(mid*2, value) == -1){
      l = mid+1;
    }
    else if(comp(mid*2, value) == 1){
      r = mid-1;
    }
    else {
      return -1;
    }
  }
  if (r < l) return -1;
}

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  int32 temp, temp2, n, m;
  temp2 = 0;
  cin >> n;

  LOOP(n){
    cin >> temp;
    v.push_back(temp2+1);
    v.push_back(temp2+temp);
    temp2 = temp+temp2;
  }
  cin >> m;
  LOOP(m){
    cin >> temp;
    cout << binary_search(temp) << endl;
  }

  return 0;
}


