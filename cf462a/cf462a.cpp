#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

typedef long int int32; typedef long long int int64;
typedef unsigned long int uint32; typedef unsigned long long int uint64;
typedef pair<int, int> ii; typedef vector<ii> vii; typedef vector<int> vi;
typedef tuple<int, int, int> iii;
typedef vector<vi> vvi;

#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define VISITED 1
#define UNVISITED -1
#define EXPLORED 2
#define FLOAT_EPSILON 1e-6

#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define LOOP(i, n) for (int i = 0; i < n; ++i)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )
#define DEBUG(x) cerr << #x << " is " << x << endl;

#define LIMIT 100


template < typename T>
void printM(T *matrix, size_t row, size_t col){
  cout << "\n";
  for(int i = 0; i < row; ++i){

    for(int j = 0; j < col; ++j){
      cout << matrix[i][j] << " \n"[j == col-1];
    }
  }
  cout << "\n";
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  map<char, bool> d = {{'o', 1}, {'x', 0}};

  char board[LIMIT][LIMIT];
  int n;
  cin >> n;
  LOOP(i, n){
    LOOP(j, n){
      cin >> board[i][j];
    }
  }
  bool r = true;
  LOOP(i, n){
    LOOP(j, n){
      int a = 0;
      if(i > 0){
        a += d[ board[i-1][j] ];
      }
      if (i < n-1){
        a += d[ board[i+1][j] ];
      }
      if (j > 0){
        a += d[ board[i][j-1] ];
      }
      if (j < n-1){
        a += d[ board[i][j+1] ];
      }
      r = r && (a%2 == 0);
    }
  }
  if (r) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}

