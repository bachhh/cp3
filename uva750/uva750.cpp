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

void generate(vector<vector<int>> &config, vector<int> &board ,int row){
  if (row >= 8){
    config.push_back(board);
  }
  else if(board[row] != -16){
    generate(config, board, row+1);
  }
  else{
    for(int i = 0; i < 8; ++i){
      bool flag = true;
      for(int j = 0; j < 8; ++j){
        if(board[j] == i || abs(row-j) == abs(i-board[j]) ){
          flag = false;
        }
      }
      if (flag){
        board[row] = i;
        generate(config, board, row+1);
      }
    }
    board[row] = -16;
  }
}

//  ***** MAIN *****
int main(){
  int i; cin >> i;
  int pos_row, pos_col;
  int counter;
  vector<int> board (8);
  vector<vector<int>> config;

  for(int n = 1; n <= i; n++){
    config.clear();
    counter = 1;
    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    cin >> pos_row >> pos_col;
    for(int i=0; i<8;++i)board[i] =-16;
    board[pos_col-1] = pos_row-1;
    generate(config, board, 0);
    for(vector<int> sol : config){
      printf("%2d     ",counter);
      for(int i : sol){
        printf(" %d", i+1);
      }

      counter++;
      printf("\n");
    }
    if (n!= i)printf("\n");
  }
  return 0;
}

