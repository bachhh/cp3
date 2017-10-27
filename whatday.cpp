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

void swap(int* a, int *b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}
int factorial(int n){
  if (n == 0 || n == 1) return 1;
  else return n*factorial(n-1);
}


map<int, char> color = {
                        {0, 'B'},
                        {1, 'G'},
                        {2, 'C'}
                       };

int compare_config(vector<int> config1, vector<int> config2){
  int i =0;
  for(; i < MIN(config1.size(), config2.size()) ;++i){
    if( color[config1[i]] < color[config2[i]] )
      return -1;
    else if (color[config1[i]] > color[config2[i]])
      return 1;
  }
  if (i < config2.size() - 1 ) return -1;
  else if(i < config1.size() - 1) return 1;
  else if ( i == config1.size()-1 && i == config2.size() -1 ) return 0;
}

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  int temp, count = 0;
  vector<int> input;

  const int total = 3;
  while(cin >> temp){
    input.push_back(temp);
    count++;
    if( count >= 9){
      int bin[total][total];
      // This bin 3D array represent the cost
      // If bin[bin_no] is chose to hold the color_int
      for(int bin_no = 0; bin_no < total; ++bin_no){
        vector<int> color;
        for(int color_int = 0; color_int < total; ++color_int){
          bin[bin_no][color_int] = 0;
          for(int other_bin = 0; other_bin < total; other_bin++){
            if(other_bin != bin_no){
              bin[bin_no][color_int] += input[other_bin*3 + color_int];
            }
          }
        }
      }

      // Basic permutation
      vector<int> permute = {0, 1, 2};
      int min_moves = INF;
      vector<int> min_config;
      // Iterate over 3! permutations
      do {
        int moves =0;
        for(int bin_no = 0; bin_no < total; ++bin_no){
          moves += bin[bin_no][permute[bin_no]];
        }
        if (moves < min_moves){
          min_moves = moves;
          min_config = permute;
        }
        else if ( moves == min_moves && (compare_config(permute, min_config) == -1) ) {
          min_config = permute;
        }

        // Remember configuration and min moves permutation
      } while(next_permutation(permute.begin(), permute.end()));

      // Output
      for(int c = 0; c < total; ++c){
        cout << color[min_config[c]];
      }
      cout << " " << min_moves << endl;
      count = 0;
      input.clear();
    }
  }
  return 0;

}

