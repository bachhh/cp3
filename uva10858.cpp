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


vector< vector<int>> li;

void solve(int n, int div, vector<int> st){
  for (int i = div; i <=sqrt(n); i++){
    if(n%i == 0){
      st.push_back(i);
      solve(n/i, i, st);
      st.pop_back();
    }
  }
  st.push_back(n);
  if (st.size() > 1)li.push_back(st);
  st.pop_back();
}

int main(){
  int n;
  cin >> n;
  while(n != 0){
    li.clear();
    if (n == 1){
      cout << 0 << endl;
    }
    else {

      vector<int> st;
      solve(n, 2, st);
      cout << li.size() << endl;
      for (int i = 0; i < li.size(); i++){
        for (int j=0; j < li[i].size(); j++){
          cout << li[i][j];
          if (j < li[i].size()-1) cout << " ";
        }
        cout << endl;
      }

    }
    cin >> n;
  }

  return 0;
}

