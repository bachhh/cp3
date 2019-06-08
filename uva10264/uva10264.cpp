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
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )
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

  int n;
  while(cin >> n){
    map<int, int> weight;
    map<int, int> potency;
    for (int i = 0;i < pow(2, n); i++){
      int temp;
      cin >> temp;
      weight[i] = temp;
    }
    int32 temp_sum; 

    for (auto const &i : weight){
      temp_sum = 0;
      int coordinate = i.first;

      // Iterate over N dimensional neighboring corner
      for (int j =0; j < n; j++){
         temp_sum += weight[(coordinate^(1 << j))];
      }
      potency[coordinate] = temp_sum;
    }

    int32 max_sum = 0;
    
    for (auto const &i : potency){
      temp_sum = 0;
      int coordinate = i.first;

      for (int j=0; j < n; j++){
        temp_sum = i.second + potency[coordinate^(1 << j) ];
        max_sum = MAX(max_sum, temp_sum);
      }

    }
    cout << max_sum << endl;
  } 
}

