#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  char matrix[2000][2000];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> matrix[i][j];
    }
  }
  int output = 0;

  for (int i = 0; i < n; i++) {
    int consec = 0;
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] == '.'){
        consec++;
      }
      if ( j == m-1 || matrix[i][j] == '*'){
        if (consec >= k){
          output += consec - k+1;
        }
        consec = 0;
      }
    }
  }

  for (int j = 0; j < m; j++) {
    int consec = 0;
    for (int i = 0; i < n; i++) {
      if (matrix[i][j] == '.'){
        consec++;
      }
      if (i == n-1 || matrix[i][j] == '*'){
        if (consec >= k){
          output += consec - k+1;
        }
        consec = 0;
      }
    }
  }

  std::cout << output << std::endl;


  return 0;
}

