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
  int a, b, c; 
  scanf("%d%d%d",  &a, &b, &c);
  uint64 a_cover = ( a % c == 0 ) ? a/c : a/c + 1;
  uint64 b_cover = ( b % c == 0 ) ? b/c : b/c + 1;
  cout << a_cover * b_cover << endl;


  return 0;
}
