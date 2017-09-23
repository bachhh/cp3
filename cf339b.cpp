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

int main(){
  int64 n, m, temp;
  cin >> n >> m;
  map<int, int> task;

  for (int i=1; i <= m; ++i){
    cin >> temp;
    task[i] = temp;
  }

  int64 cur_house = 1;
  int64 time = 0;

  for(int i =1; i <= m; ++i){
    if (task.at(i) > cur_house){
      time += task.at(i) - cur_house;
    }
    else if ( task.at(i) < cur_house){
      time += n - cur_house + task.at(i);
    }
    cur_house = task.at(i);
  }
  cout << time << endl;

  return 0;
}
