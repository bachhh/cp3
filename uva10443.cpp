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
  map<char, char> game;
  game['R'] = 'P';
  game['P'] = 'S';
  game['S'] = 'R';
  int tc;
  scanf("%d", &tc);
  int init_tc = tc;
  getchar();
  while(tc--){
    int row, column, day;
    scanf("%d %d %d", &row, &column, &day);
    getchar();
    vector< vector <char> > previous(row), next(row);
    for(int i = 0; i < row; i++){
      previous[i].resize(column); next[i].resize(column);
    }

    char temp;

    for (int r = 0; r < row; r++){
      for (int c = 0; c < column; c++){
        temp = getchar();
        previous[r][c] = temp; 
      }
      getchar();
    }
    
    while(day--){
      //Calculate the board's states for next day
      for(int r = 0; r < row; r++){
        for(int c = 0; c < column; c++){
          char winner = game.at(previous[r][c]);
          // Ternary op to avoid out of bound 
          if (  ( (r > 0) && previous[r-1][c]==winner) ||
                ( (c > 0) && previous[r][c-1]==winner) ||
                ( (r < row - 1) && previous[r+1][c]==winner) ||
                ( (c < column - 1) && previous[r][c+1]==winner ) )  {
            next[r][c]=winner;
          }
          else {
            next[r][c]=previous[r][c];
          }
        }  
      }

      for(int r = 0; r < row; r++){
        for (int c = 0; c < column; c++){
          previous[r][c] = next[r][c];
        }
      }

    }

    for(int r = 0; r < row ; r++){
      for(int c = 0; c < column; c++){
        cout << previous[r][c];
      }
      cout << endl;
    }
    cout<<endl;
  } 
  return 0;
}
