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
#define LOOP(n) for (int i = 0; i < n; ++i)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )


vector<vector<int>> queens;
int queen_board[8];
void queen_problem(int row){
  if (row > 7){
    for(int i =0;i< 8++i)
      cout << quee_board[i] << " ";
    cout << endl;
  }
  for(int i = 0; i <8; ++i){
    bool threat = false;
    queen_board[row] = i;
    // Check the queen_board for threats
    for(int j = 0; j < i && !threat; ++j){
      if (queen_board[i] == queen_board[j] ||
          abs(row - j) == abs(queen_board[row] - queen_board[j])){
        threat = true;
      }
    }

    // If no threat present, place queen of row at column i
    // Proceed to row +1
    if (!threat) queen_problem(row+1);

  }
  queen_board[row] = -1;
}

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  int k, temp;
  cin >> k;
  vector<vector<int>> board;
  queen_problem(0);
  /*
  vector<int> temp_row;
  for(int i = 0; i < k; ++i){
    board.clear();
    for(int j = 0; j < 8;++j){
      temp_row.clear();
      for (int k = 0; k < 8; ++k)}
        cin >> temp;
        temp_row.push_back(temp);
      }
      board.push_back(temp_row);
    }
  }
  */

  return 0;
}

