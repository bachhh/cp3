#include <bits/stdc++.h>

using namespace std;

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >>m;
  int matrix[100][200];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2*m; j++) {
      cin >> matrix[i][j];
    }
  }
  int counter = 0;
  for (int fl = 0; fl < n; ++fl) {
    for (int flat = 0; flat < m; ++flat) {
      if(matrix[fl][2*flat] == 1 || matrix[fl][2*flat+1] == 1 )
        counter++;
    }
  }
  std::cout << counter << std::endl;

  return 0;
}

