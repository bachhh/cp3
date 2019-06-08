#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){

  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >>n >> m;

  int matrix[100][100];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; j++) {
      char t; cin >> t;
      matrix[i][j] = t-'0';
    }
  }

  int counter[100] = {0};
  for (int j = 0; j < m; j++) {

    int maxscore = -1;
    vector<int> students;

    for (int i = 0; i < n; ++i) {
      if (matrix[i][j] >= maxscore){
        if (matrix[i][j] > maxscore) students.clear();
        maxscore = matrix[i][j];
        students.push_back(i);
      }
    }
    for (int k : students) {
      counter[k]++;
    }
  }

  int output = 0;
  for (int i = 0; i < n; ++i) {
    if (counter[i]) output++;
  }
  std::cout << output << std::endl;

  return 0;
}

