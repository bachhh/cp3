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

  //freopen("input.txt","r", stdin);
  //freopen("output.txt","w", stdout);

  int t;
  cin >> t;
  int scenario = 0;
  while(t != 0 ){
    scenario++; 
    printf("Scenario #%d\n", scenario);
    // map<team_member, team_number>
    unordered_map<int, int> member_map;
    // map<team_number, last_it>
    unordered_map<int, list<int>::iterator> pos_map;
    // map<team_number, member_in_queue_count>
    unordered_map<int, int> count_map;

    list<int>::iterator queue_it;
    list<int> queue;
    int members;
    for (int i=0; i<t; i++){
      count_map[i] = 0;
      cin >> members; 
      while(members--){
        int temp;
        cin >> temp;
        member_map[temp] = i;
      }
    }
     
    string command;
    cin >> command;

    while(command != "STOP"){

      // Insert to front of queue pop from the begin of queue
      if (command == "ENQUEUE"){
        int target; cin >> target;
        int team = member_map[target];
        list<int>::iterator last_pos;
        if (count_map[team] == 0){
          last_pos = queue.begin(); 
        } else {
          last_pos = pos_map[team]; 
        }

        pos_map[team] = queue.insert(last_pos, target);
        count_map[team]++;
      }

      else if (command == "DEQUEUE"){
       int team = member_map[queue.back()];
       count_map[team]--;
       if (count_map[team] == 0){
         pos_map[team] = queue.begin();
       }
       cout << queue.back() << endl;
       queue.pop_back();
      }
      cin >> command;
    }
    cout << endl;
    cin>>t;
  } 
  return 0;
}

