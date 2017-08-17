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
  while(tc--){
    int clown_min = 0, n;
    int student;
    scanf("%d", &n);
    while (n--){
      scanf("%d", &student);
      clown_min = (clown_min < student) ? student : clown_min;
    }
    cout << "Case " << init_tc - tc << ": " << clown_min << endl; 
  } 

  return 0;
}
