#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;

  int m[100][100];

  memset(m, 0, sizeof(m[0][0])*100*100);

  for (int i = 0; i < n; ++i) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
      cin >> m[i][j];
      sum += m[i][j];
    }

    m[i][99] = sum;
  }
  for (int j = 0; j < n; j++) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += m[i][j];
    }
    m[99][j] = sum;
  }

  int counter = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; j++) {
      if(m[99][j] > m[i][99] ){
        counter++;
      }
    }
  }

  std::cout << counter << std::endl;

  return 0;
}

