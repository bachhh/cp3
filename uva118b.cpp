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
  
  int n;
  scanf("%d", &n);
  vector< vector<char> > matrix;
  matrix.resize(n*4+1);

  for (int i = 0; i < n*4; i++){

    matrix[i].resize(n*4+1);

  }
  for (int r = 0; r < n*4; r++){
    for (int c = 0; c < n*4; c++){

      if ( c == 2*n  && r <= n && (r%2) == 0 ){
        matrix[r][c] = '0' + r;
      }
      else if ( c == 2*n  && r > n && (r%2) == 0){
        matrix[r][c] = '0' + 2*n - r ; 
      }
      else if ( r == n && c <= n ){
        matrix[r][c] = c ;
      }
      else if ( r == n && c > n ){
        matrix[r][c] = 2*n - c;
      }
      else {
        matrix[r][c] = ' ';
      }

    }
  }
  for (int r = 0; r < (n*4); r++){
    for (int c = 0; c < (n*4); c++){
      cout << matrix[r][c];
    }
    cout << endl;
  }
  return 0;
}
