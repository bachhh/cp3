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
#define LOOP(n) for (int i = 0; i < n; ++i)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

vector<vector<int>> store;

void permute(vector<bool> sieve, vector<int> array, int i, int n){
  // Edge case n = 1
  if (n == 0){
    store.push_back(array);
    return;
  }
  if (i == n){
    if (sieve[array[i] + array[i-1]] && sieve[array[i] + array[0]])
      store.push_back(array);
  }
  else {
    for( int j = i; j <= n; ++j){
      if ( sieve[array[j] + array[i-1]] ){
        std::swap(array[i], array[j]);
        permute(sieve, array, i+1, n);
        std::swap(array[i], array[j]);
      }
    }
  }
}

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  int n;
  vector<bool> sieve;
  int testcase = 1;
  for(int i = 0; i <= 31; i++){sieve.push_back(true);}
  vector<int> array;

  for(int i = 2; i<=31; ++i){
    if(sieve[i]){
      for(int j = 2; j*i <= 31; ++j){
        sieve[i*j] = false;
      }
    }
  }

  cin >> n;
  do {
    store.clear();
    array.clear();
    for(int i =1; i <= n; ++i){
      array.push_back(i);
    }

    permute(sieve, array, 1, n-1);
    cout << "Case "<< testcase++ <<":" << endl;
    std::sort(store.begin(), store.end());

    for(vector<int> v : store){
      for(int i = 0; i < v.size(); ++i){
        cout << v[i];
        if (i < v.size()-1) cout << " ";
      }
      cout << endl;
    }
  }while(cin >> n && cout << endl);

  return 0;
}

