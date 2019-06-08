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


  int counter[3] = {0, 0, 0};

  int n;
  cin >> n;
  int backs= 0, biceps=0, chests=0;

  int t;

  LOOP(i, n){
    cin >> t;
    if(i % 3 == 0) chests+= t;
    if(i % 3 == 1) biceps+= t;
    if(i % 3 == 2) backs+= t;
  }
  if ( chests > backs){
    if (chests > biceps){
      cout << "chest" << endl;
    }
    else{
      cout << "biceps" << endl;
    }
  }
  else {
    if (backs > biceps){
      cout << "back" << endl;
    }
    else {
      cout << "biceps" << endl;
    }
  }


  return 0;
}

