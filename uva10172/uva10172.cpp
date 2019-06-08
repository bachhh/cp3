#include <iostream>
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
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdin);
  const int LOAD_TIME = 1;
  const int MOVE_TIME = 2;
  int set;
  cin >> set;
  while(set--){
    int n, s, q;  
    cin >> n >> s >> q;
    stack<int> carrier;
    vector<queue<int>> cia;

    int cargo_left = 0;
    for (int i =0; i<n; i++){
      queue<int> b; 
      int cargo_no; cin >> cargo_no; 
      while(cargo_no--){
        int temp; cin>>temp;
        b.push(temp );
        cargo_left++;
      }
      cia.push_back(b);
    }

    int time = 0, current_station = 0;
    bool flag;
    while(cargo_left > 0){
      // Unloading while station not full and carrier not empty
      while(!carrier.empty() && ( (carrier.top() == current_station +1) || (cia[current_station].size() < q) ) ){
        if (carrier.top() == current_station + 1){
          cargo_left--;
        } 
        else {
          cia[current_station].push(carrier.top());
        }
        carrier.pop();
        time += LOAD_TIME;
      }

      // Loading while station not empty and carrier not full
      while( (carrier.size() < s) && !cia[current_station].empty() ){
        carrier.push(cia[current_station].front());
        cia[current_station].pop();
        time += LOAD_TIME;
      }


      if (cargo_left<1)
        break;

      // Move
      current_station = ( current_station + 1 ) % n;
      time += MOVE_TIME;
    }
    cout << time << endl;
  }
  return 0;
}

