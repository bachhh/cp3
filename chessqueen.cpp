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
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

void swap(int* a, int *b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

int c = 0;
// Each column has 1 queen
// Boards denote which row that column's queen is placed
bool queenCheck(int *board, int row, int column){
  for(int i =1; i < column; i++){
    if(board[i] == row) return false;
    if(abs(column - i) == abs(row - board[i])) return false;
  }
  return true;
}

void placeQueen(int *board, int column){
  for(int i = 1; i <= 8; ++i){
    board[column] = i;
    if(column < 8 && queenCheck(board, i, column)){
      placeQueen(board, column+1);
    }
    else if (column == 8 && queenCheck(board, i, column) ){
      c++;
      /*/print the board
      for (int i = 1; i <= 8; ++i){
        cout << i << " ";
      } cout << endl;
      for (int i = 1; i <= 8; ++i){
        cout << board[i] << " ";
      }
      cout << endl;
      cout << endl;
      */
    }
  }
  board[column] = 0;
}

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  int tc; cin >> tc;
  int dimension = 8;
  int array[9];
  placeQueen(array, 1);

  cout << c << endl;
  return 0;
}

