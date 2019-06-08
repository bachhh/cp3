#include <bits/stdc++.h>

using namespace std;
typedef long int int32;
typedef long long int int64;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;
typedef pair<int, int> ii;
typedef vector<pair<int, int>> V_ii;
const double pi = acos(-1.0);

#define PI 3.1415926535897932384626433832795
#define INF (int)1e9
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define LOOP(n) for (int z = 0; z < n; ++z)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )
#define FLOAT_PRECISION 1e-8

void swap(int* a, int *b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}


//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);

  int n, tree_count, acorn_count;
  string line;
  vector<vector<char>> g;
  vector<vector<char>>::iterator tree;
  vector<char>::iterator vertex;
  bool found;


  cin >> n;
  getline(cin, line);
  while(n--){

    g.clear();
    tree_count = acorn_count = 0;

    getline(cin, line);
    while(line[0] != '*'){

      found = false;

      for(tree = g.begin(); !found && tree != g.end(); ++tree){
        for(vertex = (*tree).begin(); !found && vertex != (*tree).end(); ++vertex){
          if (*vertex == line[1]){
            (*tree).push_back(line[3]);
            found = true;
          }
          else if ( *vertex == line[3]){
            (*tree).push_back(line[1]);
            found = true;
          }
        }
      }
      if (!found){
        g.push_back(vector<char> {line[1], line[3]});
        tree_count++;
      }
      getline(cin, line);
    }

    getline(cin, line);
    for(int i = 0; i < line.size(); i += 2 ){
      found = false;
      for(tree = g.begin(); !found && tree != g.end(); ++tree){
        for(vertex = (*tree).begin(); !found && vertex != (*tree).end(); ++vertex){
          if (*vertex == line[i]){
            found = true;
          }
        }
      }

      if (!found){
        acorn_count++;
      }
    }
    printf("There are %d tree(s) and %d acorn(s).\n", tree_count, acorn_count);
  }

  return 0;
}

