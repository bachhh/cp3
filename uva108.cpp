#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  int matrix[100][100];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
      if (i > 0) matrix[i][j] += matrix[i-1][j];
      if (j > 0) matrix[i][j] += matrix[i][j-1];
      if (i > 0 && j > 0) matrix[i][j] -= matrix[i-1][j-1];
    }
  }

  int maxsum = -INT_MAX + 10;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      for(int k = i; k < n; ++k){
        for(int l = j; l < n; ++l){
          int sum = matrix[k][l];
          if (i > 0 ) sum -= matrix[i-1][l];
          if (j > 0 ) sum -= matrix[k][j-1];
          if (i > 0 && j > 0) sum += matrix[i-1][j-1];
          maxsum = max(maxsum, sum);
        }
      }
    }
  }

  std::cout << maxsum << std::endl;
  return 0;
}

