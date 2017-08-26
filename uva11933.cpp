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
  int32 n;
  scanf("%ld", &n);
  while(n != 0){
    int32 a_n = 0, b_n = 0, temp = 0;
    while(n != 0){
      // get least sig bit on
      temp = n & (-n); 
      // turn on that bit in a
      a_n = a_n | temp; 
      // turn that bit off
      n =  n & (~temp);
      // reset temp
      temp = 0;
      // get the next sig bit on
      temp = n & (-n); 
      // turn that bit on in b
      b_n = b_n | temp;
      // turn that bit off
      n = n & (~ temp);
    }
    cout << a_n << ' ' << b_n << endl;
    scanf("%ld", &n);
  }
  return 0;
}
