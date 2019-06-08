#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  vector<vector<int>> matrix(n, vector<int>(n, 0));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }


  int i = 0, j = 0;
  int sum1 = 0, sum2 = 0;
  while(i < n && j < n){
    sum1 += matrix[i][j];
    sum2 += matrix[n-i-1][j];
    i++; j++;
  }

  std::cout << abs(sum1 - sum2) << std::endl;

  return 0;
}

