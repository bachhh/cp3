#include <bits/stdc++.h>

using namespace std;

#define LIMIT 30

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int tc; cin >> tc;

  int64_t matrix[LIMIT][LIMIT][LIMIT];
  int64_t temp;
  while(tc--){
    int a, b, c;
    cin >> a >> b >> c;

    for (int i = 0; i < a; ++i) {
      for (int j = 0; j < b; ++j) {
        for (int k = 0; k < c; ++k) {
          cin >> temp;
          if(i>0) temp += matrix[i-1][j][k];
          if(j>0) temp += matrix[i][j-1][k];
          if(k>0) temp += matrix[i][j][k-1];
          if (i > 0 && j > 0) temp -= matrix[i-1][j-1][k];
          if (j > 0 && k > 0) temp -= matrix[i][j-1][k-1];
          if (i > 0 && k > 0) temp -= matrix[i-1][j][k-1];

          if(i > 0 && j > 0 && k > 0) temp += matrix[i-1][j-1][k-1];

          matrix[i][j][k] = temp;
        }
      }
    }

    int64_t maxsum = INT64_MIN;
    std::cout << maxsum << std::endl;
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b; j++) {
        for (int k = 0; k < c; ++k) {
          for (int x = i; x < a; ++x) {
            for (int y = j; y < b; ++y) {
              for (int z = k; z < c; ++z) {
                int64_t sum = matrix[x][y][z];
                if (i > 0) sum -= matrix[i-1][y][z];
                if (j > 0) sum -= matrix[x][j-1][z];
                if (k > 0) sum -= matrix[x][y][k-1];
                if (i>0 && j > 0) sum += matrix[i-1][j-1][z];
                if (j>0 && k > 0) sum += matrix[x][j-1][k-1];
                if (i>0 && k > 0) sum += matrix[i-1][y][k-1];
                if(i > 0 && j > 0 && k > 0) sum -= matrix[i-1][j-1][k-1];
                maxsum = max<int64_t>(maxsum, sum);
              }
            }
          }
        }
      }
    }
    std::cout << maxsum << std::endl;
  }


  return 0;
}

