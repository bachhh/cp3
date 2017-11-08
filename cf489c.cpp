#include <iostream>
#include <assert.h>
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


int sum(const string s){
  if (s == "-1") return -1;
  int r = 0;
  for(char c : s){
    r += (int) (c - '0');
  }
  return r;
}

bool down_str(string &s,const int pos){
  if((pos == 0 && s[pos] == '1') || pos<0 ){
    return false;
  }
  else{
    s[pos]--;
    if (s[pos]<'0'){
      s[pos] = '9';
      return down_str(s, pos-1);
    }
  }
  return true;
}

bool up_str(string &s,const int pos){
  if((pos==0 && s[pos] == '9') || pos < 0 ){
    return false;
  }
  else{
    s[pos]++;
    if (s[pos] > '9'){
      s[pos] = '0';
      return up_str(s, pos-1);
    }
  }
  return true;
}

//  ***** MAIN *****
int main(){
  int m, s;
  cin >> m >> s;
  int s1 = s;
  string mi = "";
  string ma = "";


  string rmin = "-1", rmax="-1";
  for(int d = 0; s1 <= 9*(m-d) && d < m; ++d){
    if (s1 < 9*(m-d)){
      if (s1 > (9*(m-d-1))){
        mi += (s1%9)+'0';
        s1 -= s1%9;
      }
      else {
        if( d == 0 && s1 != 0 ){
          mi += '1';
          s1--;
        }
        else {
          mi += '0';
        }
      }
    }
    else if (s1 == 9*(m-d)){
      mi += '9';
      s1 -= 9;
    }
  }

  if( s1 != s ){
    rmin = mi;
  }

  s1 = s;
  for( int d = 0; s1 <= 9*(m-d) && d < m; ++d) {
    if(s1 < 9 && s1 > 0){
      ma += (s1, m, s%9) + '0';
      s1 = 0;
    }
    else if (s1 >= 9){
      ma+= '9';
      s1 -= 9;
    }
    else if (s1 == 0){
      if (d == 0 ) break;
      else{
        ma+= '0';
      }
    }
  }

  if (s1 != s ){
    rmax = ma;
  }
  if (m == 1 && s == 0){
    rmin = '0'; rmax = '0';
  }
  cout << rmin << " " << rmax << endl;


  return 0;
}


