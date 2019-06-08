#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define VISITED 1
#define UNVISITED -1

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define LIMIT 1000

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);


  int n; cin >> n;
  int counter = 0;
  char board[LIMIT][LIMIT];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {board[i][j] = 'C'; counter++;}
      else if( (i > 0 && board[i-1][j] != 'C') ||
               (j > 0 && board[i][j-1] != 'C') ){
        board[i][j] = 'C';
        counter++;
      }
      else board[i][j] = '.';
    }
  }
  std::cout << counter << std::endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << board[i][j];
      if (j==n-1) cout << endl;
    }
  }



  return 0;

}

