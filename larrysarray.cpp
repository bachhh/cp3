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

// Recursive style
void bubbleSort(vector<int> &v ){

  int i = 0;
  int limit = v.size()-3;
  while(i<limit){

  }
}

void swap(list<int> &l, list<int>::iterator a, list<int>::iterator b){
    auto c= std::next(b);
    auto d = std::next(a);
    l.splice(c, l, a);
    l.splice(d, l, b);
}

// Iterative style
bool roboSort(list<int> &l){
  if (l.size() <= 3){
    auto first = l.begin();
    auto second = std::next(first);
    auto third = std::next(second);
    return  (*first == 1  && *second == 2 && *third == 3) ||
            (*first == 3  && *second == 1 && *third == 2) ||
            (*first == 2  && *second == 3 && *third == 1);
  }
  else {
    list<int>::iterator cur, temp;
    int i, size = l.size();
    // from start to third last of list
    for ( cur = l.begin(), i = 1; cur != l.end() && i < size-1; ++i,++cur ){
      // current node is not in correct position
      if (*cur != i){

        auto correct = find(l.begin(), l.end(), i);
        int d = distance(cur, correct);
        if (d==1){
          swap(l, cur, correct);
          swap(l, cur, std::next(cur));
          cur = correct;
        }
        else {
          if (d%2 == 1){
            auto b = std::prev(correct);
            auto a = std::prev(b);
            swap(l, a, b);
            swap(l, correct, a);
            --d;
          }
          if (d > 0 && d%2 == 0){
            l.splice(cur, l, correct);
            cur = correct;
          }
        }
      }
    }

    // Check 2 last item in the list;
    auto last =   std::prev(l.end());
    auto lastlast = std::prev(last);
    return *lastlast < *last;
  }
}

int main(){
  int tc, n, temp;
  cin >> tc;

  list<int> l;

  while(tc--){
    l.clear();
    cin >> n;
    while(n--){
      cin >> temp;
      l.push_back(temp);
    }

    if(roboSort(l)){
      cout << "YES" << endl;
      continue;
    }
    cout << "NO" << endl;

  }

  return 0;
}
