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

// Powerset recursive
vector<vector<int>> powersetRecur(vector<int> &list){
  vector<vector<int>> output;
  vector<int> empty = vector<int>();
  if (!list.empty()){
    int new_member = list.back();
    list.pop_back();
    output = powersetRecur(list);
    vector<vector<int>> copy = output;
    for (int i =0; i < output.size(); ++i){
      output[i].push_back(new_member);
    }
    for(int i =0; i < copy.size(); ++i){
      output.push_back(copy[i]);
    }
  }
  else {
    output.push_back(empty);
  }
  return output;
}

// Powerset Binary
vector<vector<int>> powersetIter(vector<int> list){
  vector<vector<int>> output;
  vector<int> temp;
  int size = list.size();
  for (int i = 0; i < (1 << size); ++i){
    cout << i << endl;
    for (int bit = 0; bit < size; ++bit){
      cout << bit << endl;
      if (i & (1 << bit) ){
        temp.push_back(list[bit]);
      }
    }
    output.push_back(temp);
    temp.clear();
  }
  return output;
}

// Subset of size
vector<vector<int>> subsetSize(vector<int> list, int size){
  vector<int> in, out;
  vector<vector<int>> output;
  for (int i = 0; i < list.size(); ++i){
    if (i < size)in.push_back(list[i]);
    else out.push_back(list[i]);
  }
  output.push_back(in);
  for(int o = 0; o < out.size(); ++o){
    for (int i=0; i < in.size(); ++i){
      swap(out[o], in[i]);
      output.push_back(in);
      swap(out[o], in[i]);
    }
  }
  return output;
}

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  vector<vector<int>> test = subsetSize(v, 4);

  return 0;
}
