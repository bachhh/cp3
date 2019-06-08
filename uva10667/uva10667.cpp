#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tc; cin >> tc;
  while(tc--){
    int s; cin >> s;
    int64_t matrix[101][101];

    for (int i = 0; i < s; i++) {
      for (int j = 0; j < s; j++) {
        matrix[i][j] = 1;
      }
    }

    int n; cin >> n;
    int r1, c1, r2, c2;
    for (int i = 0; i < n; i++) {
      cin >> r1 >> c1 >> r2 >> c2;
      for (int j = r1-1; j < r2; j++) {
        for (int k = c1-1; k < c2; ++k) {
          matrix[j][k] = -9999;
        }
      }
    }

    for (int i = 0; i < s; i++) {
      for (int j = 0; j < s; j++) {
        if(i > 0) matrix[i][j] += matrix[i-1][j];
        if(j > 0) matrix[i][j] += matrix[i][j-1];
        if(i >0 && j > 0) matrix[i][j] -= matrix[i-1][j-1];
      }
    }

    int64_t maxsum = 0;
    for (int i = 0; i < s; i++) {
      for (int j = 0; j < s; j++) {
        for (int x = i; x < s; ++x) {
          for (int y = j; y < s; ++y) {

            int64_t sum = matrix[x][y];
            if(i > 0) sum -= matrix[i-1][y];
            if(j > 0) sum -= matrix[x][j-1];
            if(i > 0 && j > 0) sum += matrix[i-1][j-1];
            maxsum = max(maxsum, sum);

          }
        }
      }
    }
    std::cout << maxsum << std::endl;
  }

  return 0;
}

