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

void recur_travel(int map[],int shop_left, int from, int d, int next){

}

int matrix[1025][1025];
//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  int k, temp;
  vector<int> a;
  cin >> k;
  LOOP(12){
    cin >> temp;
    a.push_back(temp);
  }
  int min_month = 13;
  for(int binary =0;binary < (1<<12); ++binary){
    int total_bit =0;
    int growth =0;
    for(int bit = 0; bit< 12; ++bit){
      if(binary & (1<<bit)){
        total_bit++;
        growth += a[bit];
      }
    }
    min_month = (growth >= k) ? MIN(total_bit, min_month) : min_month;
  }
  cout << ((min_month<13) ? min_month : -1 )<< endl;
}


