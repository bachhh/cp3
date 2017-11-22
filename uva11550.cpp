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
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t, n, m, count, a, b;
  int IM[8][28];
  int AM[8][8];

  cin >> t;
  bool incident;
  while(t--){
    cin >> n >> m;
    incident = true;

    for(int row = 0; row < n; row++){
      for(int col = 0; col < m; ++col){
        cin >> IM[row][col];
      }
    }

    // Tranpose the incident matrix to adjacency matrix
    // Check if any value is greater than 1
    for(int i = 0; i < n; ++i){
      for( int j = 0; j < n; ++j){
        AM[i][j] = 0;
      }
    }

    for(int col = 0; incident && col < m; ++col){
      count = 0;
      a = b = -1;
      // For each edge get the index of the vertex they connected to
      for(int row = 0; incident && row < n; ++row){
        if ( IM[row][col] == 1 ){
          count++;

          if (a == -1){ a = row; }
          else if (b == -1){ b = row; }
        }
      }

      if (count != 2){
        incident = false;
      }
      else {
        AM[a][b]++;
        AM[b][a]++;
      }

    }

    for(int i = 0; incident && i < n; ++i){
      for( int j = 0; incident && j < n; ++j){
        if (AM[i][j] >= 2){
          incident = false;
        }
      }
    }

    if (incident){
      cout << "Yes";
    }
    else {
      cout << "No";
    }
    cout << endl;
  }

  return 0;
}

