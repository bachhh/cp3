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
  char c; 
  string output;
  int limit = 100;
  while(limit--){
     c = getchar();
     if (c == 'A' || c == 'I' || c == 'Y' || c == 'U' || c == 'E' || c == 'O' ||
         c == 'a' || c == 'i' || c == 'y' || c == 'u' || c == 'e' || c == 'o'){
       continue;
     } 
     else if (c== '\n'){
       break;
     }
     else {
       output += '.';
       output += tolower(c);
     }
  }
  cout << output << endl;
  
  return 0;
}
