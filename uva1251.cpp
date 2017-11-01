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


//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  int k, min_move = INF;
  string a, b, from, to, temp1, temp2;
  bool match;
  while(cin >> k && k != 0){
    map<string, string> dict;
    while(k--){
      cin >> a >> b;
      dict[a] = b;
    }
    cin >> from >> to;

    // Transforming strings
    queue<string> q;
    q.push(from);
    q.push("");
    match = false;
    int count = 0;
    while(!q.empty()){
      temp1 = q.front();
      q.pop();
      if(temp1.empty()){
        if(q.size() > 0) q.push("");
        count++;
      }
      else if (temp1.size() > to.size()){
        continue;
      }
      else if (temp1 == to){
        match = true;
        break;
      }
      else {
        // Try every possible substitution
        for(map<string, string>::iterator it = dict.begin(); it != dict.end(); ++it){
          temp2 = temp1;
          // Simultanously replace all non-overlapping occurence, left-most precedency
          size_t pos = 0;
          while((pos = temp2.find(it->first, pos)) != string::npos){
            temp2.replace(pos, (it->first).length(), it->second);
            pos += (it->second).length();
          }
          // Only continue if there is change
          if (temp2 != temp1){
            q.push(temp2);
          }
        }
      }
    }
    cout << (match?count:-1) << endl;
  }
}

