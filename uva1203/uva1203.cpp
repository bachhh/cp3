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

struct Query {
  int id;
  int period;
  int time;
};

struct comparison{
  bool operator()( Query &q1, Query &q2){
    if (q1.time != q2.time) return q1.time > q2.time;
    else return q1.id > q2.id;
  }
};

int main(){
  string n;
  int k;
  int id, p;

  priority_queue<int, vector<Query>, comparison> pq;
  while( cin >> n && n !=  "#"){
    cin >> id >> p;
    Query q;q.time = p; q.id = id; q.period = p;
    pq.push(q);
  }

  cin >> k;
  while(k--){
    Query temp = pq.top();
    cout << pq.top().id << endl;
    temp.time = temp.time + temp.period;
    pq.push(temp);
    pq.pop();
  }

  return 0;
}

