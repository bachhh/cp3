#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <cmath>
#include <string>
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



void merge_s(vector<int> &v, int from, int mid, int to, int &count ){

  queue<int> left, right;
  for( int i=from; i <= mid; ++i){
    left.push(v[i]);
  }
  left.push(INF);

  for (int i=mid+1; i <= to; ++i){
    right.push(v[i]);
  }
  right.push(INF);

  for(int i = from; i <= to; ++i){
    if (left.front() < right.front()){
      v[i] = left.front();
      left.pop();
    }
    else if(right.front() < left.front()){
      v[i] = right.front();
      right.pop();
      count += left.size()-1;
    }
  }
}

int mergeSort_s(vector<int> &v, int from, int to, int &count){
  if (from < to){
    mergeSort_s(v, from, (to+from)/2, count);
    mergeSort_s(v, (to+from)/2+1, to, count);
    merge_s(v, from, (to+from)/2, to, count);
  }
}

int main(){
  int tc, l, temp; cin >> tc;
  vector<int> v1;
  for (int i : v1){
    cout << i << endl;
  }
  while(tc--){
    cin >> l;
    v1.clear();
    while(l--){
      cin >> temp;
      v1.push_back(temp);
    }
    int count = 0;
    mergeSort_s(v1, 0, v1.size()-1, count);
    cout << "Optimal train swapping takes " << count << " swaps." << endl;
  }
  return 0;
}
