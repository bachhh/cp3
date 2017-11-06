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

int hamming_dist(string clip, string movie_sub_str){
  int r =0;
  for(int i = 0; i < clip.size(); ++i){
    if (clip[i] != movie_sub_str[i]) r++;
  }
  return r;
}

int compare_string(string clip, string movie){
  if(movie.size() < clip.size()){
    return INF;
  }
  else{
    int min_dist = INF;
    for(int start = 0; start <= (movie.size() - clip.size()); start++){
      min_dist = MIN(hamming_dist( clip, movie.substr(start, clip.size() )), min_dist);
    }
    return min_dist;
  }
}

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  int M, Q; cin >> M >> Q;
  string temp;
  vector<string> database;
  LOOP(M){
    cin >> temp;
    database.push_back(temp);
  }

  LOOP(Q){
    int min_dist = INF;
    int min_index = INF;
    cin >> temp;
    for(int i = 0; i < database.size(); ++i){
      if( min_dist > compare_string(temp, database[i])){
        min_dist = compare_string(temp, database[i]);
        min_index = i;
      }
    }
    cout << min_index+1 << endl;
  }
  return 0;
}

