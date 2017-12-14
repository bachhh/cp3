#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

typedef long int int32; typedef long long int int64;
typedef unsigned long int uint32; typedef unsigned long long int uint64;
typedef pair<int, int> ii; typedef vector<ii> vii; typedef vector<int> vi;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef vector<vi> vvi;

#define PI 3.1415926535897932384626433832795
#define VISITED 1
#define UNVISITED -1
#define EXPLORED 2
#define FLOAT_EPSILON 1e-6

#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define LIMIT 1001

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);

  // @@@ ENCODE STATES @@@
  queue<pair<string, string>> q;
  pair<string, string> p;
  map<char, string > reversemoves= { {'a', "V1"}, {'b', "V2"}, {'c', "V3"}, {'d', "H1"}, {'e', "H2"}, {'f', "H3"}};
  map<string, string> statemove;
  string movement, config, nextconfig;

  // Solve every reachable state
  statemove["123456789"] = ""; q.push({"","123456789"});
  while(!q.empty()){
    p = q.front(); q.pop();
    movement = p.first;
    config = p.second;
    for (char c = 'a'; c <= 'f'; ++c) {
      if(movement.size() > 2*2 && c == movement[movement.size()-1] &&
                                  c == movement[movement.size()-2]){
        continue;
      }
      // 0 1 2
      // 3 4 5
      // 6 7 8
      else{
        nextconfig = config;
        if (c == 'a'){
          nextconfig[0] = config[6];
          nextconfig[3] = config[0];
          nextconfig[6] = config[3];
        }
        if (c == 'b'){
          nextconfig[1] = config[7];
          nextconfig[4] = config[1];
          nextconfig[7] = config[4];
        }
        if (c == 'c'){
          nextconfig[2] = config[8];
          nextconfig[5] = config[2];
          nextconfig[8] = config[5];
        }
        if (c == 'd'){
          nextconfig[0] = config[1];
          nextconfig[1] = config[2];
          nextconfig[2] = config[0];
        }
        if (c == 'e'){
          nextconfig[3] = config[4];
          nextconfig[4] = config[5];
          nextconfig[5] = config[3];
        }
        if (c == 'f'){
          nextconfig[6] = config[7];
          nextconfig[7] = config[8];
          nextconfig[8] = config[6];
        }
        if(statemove.find(nextconfig) == statemove.end()){
          q.push({movement+c, nextconfig});
          statemove[nextconfig] = movement+c;
        }
        else if(statemove[nextconfig].size() == movement.size()+1 ){
          //std::cout << nextconfig << "|" << movement+c << endl;
        }
      }
    }
  }
  string input;
  char c;
  bool end = false;

  while(!end){
    input = "";
    while(!q.empty()) q.pop();
    for (int i = 0;  i < 9; ++i) {
      cin >> c;
      if (c== '0'){ end = true; return 0;}
      input += c;
    }
    if(statemove.find(input) != statemove.end()){
      movement = statemove[input];
      int s = movement.size();
      std::cout << s << " ";
      for (int i = s-1; i >=0; --i) {
        cout << reversemoves[movement[i]];
      }
      cout << std::endl;
    }
    else{
      std::cout << "Not solvable" << std::endl;
    }
  }

  return 0;
}

