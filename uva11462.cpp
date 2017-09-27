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

int main(){
  // Test IO
  ios::sync_with_stdio(false);
  int n, count[101], temp;
  while(cin>>n && n != 0){
    memset(count, 0, sizeof(count));
    for (int i =0; i < n;++i){
      cin >> temp;
      count[temp]++;
    }

    for(int i=0; i <= 100; ++i){
      for (int j=count[i]; j > 0; --j){
        n--;
        cout << i;
        if (n) cout << " ";
      }
    }
    cout << endl;

  }

  return 0;
}
