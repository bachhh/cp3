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
bool check_matrix(int matrix[][3]){
  for (int r=0; r<3; r++){
    for (int c=0; c<3; c++){
      if (matrix[r][c]) return false;
    }
  }
  return true;
}

int main(){

  //freopen("input.txt","r", stdin);
  //freopen("output.txt","w", stdout);
  int tc;
  cin >> tc;
  int prev[3][3];
  char temp; 

  while(tc--){
    for (int r=0; r<3; r++){
      for (int c=0; c<3; c++){
        cin >> temp;
        prev[r][c] = (int) temp - '0';
      }
    }

    
    int next[3][3];
    for(int r=0;r<3;r++){
      for(int c=0;c<3;c++){
        next[r][c] = prev[r][c];
      }
    }
    int count = -1;
    
    while(true){
      for(int r=0; r<3; r++){
        for(int c=0; c<3; c++){
          int value = 0;
          if(r > 0) value^= prev[r-1][c];
          if(c > 0) value^= prev[r][c-1];
          if(r < 2) value^= prev[r+1][c];
          if(c < 2) value^= prev[r][c+1];
          next[r][c] = value;
        }
      }

      if (check_matrix(prev)) break;

      for(int r=0;r<3;r++){
        for(int c=0;c<3;c++){
          prev[r][c] = next[r][c];
        }
      }
      count++;
    }
   
    cout << count << endl;
  }
}

