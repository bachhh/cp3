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

void swap(int* a, int *b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  int n, temp;
  cin >> n;
  queue<int> math;
  queue<int> code;
  queue<int> sport;
  for(int i =1; i<=n; ++i){
    cin >> temp;
    if(temp == 1) code.push(i);
    if(temp == 2) math.push(i);
    if(temp == 3) sport.push(i);
  }

  int teams = MIN(code.size(), MIN(math.size(), sport.size()));
  cout << teams << endl;
  if (teams>0){
    for(int i =0; i < teams; ++i){
      printf("%d %d %d\n", code.front(), math.front(), sport.front());
      code.pop();
      math.pop();
      sport.pop();
    }
  }

  return 0;
}

