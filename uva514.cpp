#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <vector>
#include <map>
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


int main(){

  //freopen("input.txt","r", stdin);
  //freopen("output.txt","w", stdout);

  int block; 
  while(true){ 
    
    scanf("%d", &block);
    if (block == 0)
      break;
    
    while(true){

      int coach;

      scanf("%d", &coach);

      if(coach == 0){
        cout << endl;
        break;
      }

      queue<int> queue; 
      queue.push(coach);

      for (int i = 1; i < block; i++){
        scanf("%d", &coach);
        queue.push(coach);
      }
       
      stack<int> stack;

      for (int a_coach = 1; a_coach <= block; a_coach++){

        stack.push(a_coach);  
        while( !stack.empty() && queue.front() == stack.top()){
          stack.pop();
          queue.pop();
          if(queue.empty()) break;
        }
      }
      if (stack.empty()) cout << "Yes" << endl;
      else cout << "No" << endl;
    }


    
  }
  return 0;
}
