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
  int row = n*2+1;
  int column = n*4+1;
  matrix.resize(row);

  for (int i = 0; i < row; i++){
    matrix[i].resize(column);
  }

  for (int r = 0; r < row; r++){
    for (int c = 0; c < column; c++){
      if (c%2 == 1){
        matrix[r][c] = ' ';
      }
      else {
        char value = '0' -abs(r-n)-abs(c/2-n) + n ;
        if (value < '0') value = ' ';
        matrix[r][c] = value;
      }
    }
  }

  for (int r = 0; r < row; r++){
    for (int c = 0; c < column; c++){
      if (c >= 2*n && matrix[r][c] == '0'){
        cout<<matrix[r][c];
        break;
      }
      else{
        cout << matrix[r][c];
      }
    }

    cout << endl;
  }
  return 0;
}
