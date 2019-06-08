#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <queue>
#include <deque>
#include <iterator>
#include <bitset>

using namespace std;

typedef long int int32;
typedef long long int int64;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;

const double pi = acos(-1.0);

#define PI 3.1415926535897932384626433832795
#define INF (int)1e9
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)


int main(){
  freopen("input.txt","r", stdin);
  // freopen("output.txt","r", stdin);

  int tc;
  scanf("%d", &tc);
  int init_tc = tc;
  getchar();
  while(tc--){
    string line;
    int female = 0, male = 0;
    getline(cin, line); 
    for (char& c : line){
      if (c == 'F') female++;
      else if (c == 'M') male++;
    }
    if (female == male && female > 1 && male > 1){
      cout << "LOOP" << endl;
    }
    else {
      cout << "NO LOOP" << endl;
    }
    
  } 

  return 0;
}
