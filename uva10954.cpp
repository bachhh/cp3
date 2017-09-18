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

vector<stack<char>> port;

int main(){

  int n;
  while( cin >> n && n != 0){
    priority_queue<int, vector<int>, greater<int> > list;
    int temp;

    while(n--){
      cin >> temp;
      list.push(temp);
    }

    // Recursively add 2 smallest numbers in the list until 1 left
    int total = 0;
    while(list.size() > 1){
      int sum = list.top();
      list.pop();
      sum+= list.top();
      list.pop();
      total += sum;
      list.push(sum);
    }
    cout << total << endl;
  }
  return 0;
}

