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
vector<int> queen_board(8);

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  int N, k, temp;
  while(cin >> N){
    cin >> k;
    int max_config = 0, max_score = 0;
    vector<int> all_tracks;
    LOOP(k){
      cin >> temp;
      all_tracks.push_back(temp);
    }

    for(int binary=0; binary < (1 << k) ; ++binary){
      int score = 0;
      for(int bit =0; bit < k; ++bit){
        if( binary & (1 << bit)){
          score += all_tracks[bit];
        }
      }
      if (score >= max_score && score <= N){
        max_score = score;
        max_config = binary;
      }
    }
    for(int bit =0; bit < k; ++bit){
      if (max_config & (1 << bit)){
        cout << all_tracks[bit] << " ";
      }
    }
    cout << "sum:" << max_score << endl;

  }
  return 0;
}

