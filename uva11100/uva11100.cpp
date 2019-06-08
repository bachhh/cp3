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

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);

  int n, tempi, count, same;
  vector<int> v, temp;
  vector<vector<int>> result;
  vector<int>::iterator it, outer;
  while(cin >> n && n){
    result.clear();
    count = 1;
    v.clear();
    LOOP(n){
      cin >> tempi;
      v.push_back(tempi);
    }
    sort(v.begin(), v.end());
    same = count = 1;
    for(int i =1; i < v.size(); ++i){
      if (v[i] == v[i-1])same++;
      else same = 1;
      count = max(count, same);
    }

    it = v.begin();

    for(int i =0; i<count; ++i){
      temp.clear();
      temp.push_back(v[i]);
      result.push_back(temp);
    }
    v.erase(it, it+count);

    cout << result.size()<< endl;

    it = v.begin();
    same = 0;

    for(int i = 0; i < v.size();i++ ){
      while(v[i] <= *(result[same].end() - 1)){
      }
      result[same].push_back(v[i]);
        same = (same+1)%count;
    }

    for(vector<int> a : result){
      for(int i = 0; i < a.size(); ++i){
        cout << a[i];
        if (i < a.size()-1) cout << " ";
        else cout << endl;
      }
    }
    cout << endl;
  }
  return 0;
}


