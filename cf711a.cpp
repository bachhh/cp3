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

int main(){
  // Test IO
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  string s;
  string temp;
  bool flag= false;
  while(n--){
    cin >> temp;
    if( !flag && temp[0] == 'O' && temp[1] == 'O'){
      temp[0] = '+';
      temp[1] = '+';
      flag = true;
    }
    else if(!flag && temp[3] == 'O' && temp[4] == 'O'){
      temp[3] = '+';
      temp[4] = '+';
      flag = true;
    }
    s += temp + '\n';
  }
  if (flag){
    cout << "YES" << endl;
    cout << s;
    return 0;
  }
  cout << "NO" << endl;

  return 0;
}
